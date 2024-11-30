# README

This project is designed to automate calculations and generate data and plots with minimal user intervention. By simply running the provided shell script, the entire process, including compilation, execution, and data visualization, will be handled automatically.

## How to Use

### Prerequisites
Before running the script, ensure that the following are installed on your system:
- GCC (for compiling the C program)
- Python 3 (for running Python scripts)
- Virtual environment support for Python (`venv`)
- ~~Required Python packages listed in `requirements.txt`~~

### Steps to Run
1. Open a terminal in the project directory.
2. Run the following command:

   ```bash
   sh run.sh
   ```

That's it! The script will automatically perform the following steps:
- Compile the C program (`calculation.cpp`) using `gcc`.
- Execute the compiled program to generate specific output files (`specific_output.txt` and `results_omega_*.txt`).
- Create a Python virtual environment and install the necessary Python packages.
- Run the Python script (`main.py`) to generate plots based on the computed data.
- Clean up the virtual environment after use.

### Outputs
After successful execution, the following will be generated:
- **Data Files:** The calculated results will be saved in files like `specific_output.txt` and `results_omega_*.txt`.
- **Plots:** Visualizations will be generated and saved in the appropriate format as defined by `main.py`.

### Example
To start the process, simply run:
```bash
sh run.sh
```

After completion, you should find the generated data files and plots in the current directory.

### Notes
- If any error occurs during the execution, the script will stop, and an error message will be displayed.
- Ensure that you have write permissions in the project directory.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
