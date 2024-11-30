#include <stdio.h>
#include <math.h>

// Constants
#define HH (9.779 / 0.7) // For t(z) calculation
#define CC (2997.9 / 0.7) // For r(z) calculation
#define Z_MAX 20.0    // Maximum z value for the output file
#define Z_STEP 0.01    // Step for z in the output file
#define INTERNAL_STEP 0.0001 // Fine-grained step for high precision

// E(z) function
double E(double z, double omega_m, double omega_k, double omega_l) {
    return sqrt(omega_m * pow(1 + z, 3) +
                omega_k * pow(1 + z, 2) +
                omega_l);
}

// Integration for t(z)
double integrate_t(double z, double omega_m, double omega_k, double omega_l) {
    double sum = 0.0;
    double z_current;
    for (z_current = 0.0; z_current < z; z_current += INTERNAL_STEP) {
        double z_next = z_current + INTERNAL_STEP;
        double f1 = 1.0 / (E(z_current, omega_m, omega_k, omega_l) * (1 + z_current));
        double f2 = 1.0 / (E(z_next, omega_m, omega_k, omega_l) * (1 + z_next));
        sum += 0.5 * (f1 + f2) * INTERNAL_STEP;
    }
    return sum * HH;
}

// Integration for r(z)
double integrate_r(double z, double omega_m, double omega_k, double omega_l) {
    double sum = 0.0;
    double z_current;
    for (z_current = 0.0; z_current < z; z_current += INTERNAL_STEP) {
        double z_next = z_current + INTERNAL_STEP;
        double f1 = 1.0 / E(z_current, omega_m, omega_k, omega_l);
        double f2 = 1.0 / E(z_next, omega_m, omega_k, omega_l);
        sum += 0.5 * (f1 + f2) * INTERNAL_STEP;
    }
    return sum * CC;
}

// Write full results to a file and print specific z values to standard output
void calculate_and_print_results(const char *filename, double omega_m, double omega_k, double omega_l, double z_values[], int z_count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", filename);
        return;
    }

    fprintf(file, "z\tt(z)\tr(z)\n");

    printf("Results for Omega_m=%.1f, Omega_k=%.1f, Omega_L=%.1f:\n", omega_m, omega_k, omega_l);
    printf("z\tOmega_m\tOmega_k\tOmega_L\tt(z)\tr(z)\n");

    for (double z = 0.0; z <= Z_MAX; z += Z_STEP) {
        double t_z = integrate_t(z, omega_m, omega_k, omega_l);
        double r_z = integrate_r(z, omega_m, omega_k, omega_l);
        fprintf(file, "%.2f\t%.6f\t%.6f\n", z, t_z, r_z);

        // Print specific z values to standard output
        for (int i = 0; i < z_count; i++) {
            if (fabs(z - z_values[i]) < Z_STEP / 2) {
                printf("%.0f\t%.1f\t%.1f\t%.1f\t%.6f\t%.6f\n", z, omega_m, omega_k, omega_l, t_z, r_z);
            }
        }
    }

    fclose(file);
}

int main() {
    // Parameter sets
    double parameters[3][3] = {
        {1.0, 0.0, 0.0}, // (Omega_m, Omega_k, Omega_L)
        {0.3, 0.7, 0.0},
        {0.3, 0.0, 0.7}
    };

    // z values for standard output
    double z_values[] = {1, 3, 5, 10};
    int z_count = sizeof(z_values) / sizeof(z_values[0]);

    // Output filenames
    const char *filenames[3] = {
        "results_omega_1_0_0.txt",
        "results_omega_0.3_0.7_0.txt",
        "results_omega_0.3_0_0.7.txt"
    };

    // Calculate and save results for each parameter set
    for (int i = 0; i < 3; i++) {
        double omega_m = parameters[i][0];
        double omega_k = parameters[i][1];
        double omega_l = parameters[i][2];
        calculate_and_print_results(filenames[i], omega_m, omega_k, omega_l, z_values, z_count);
    }

    return 0;
}
