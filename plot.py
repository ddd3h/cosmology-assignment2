import numpy as np
import matplotlib.pyplot as plt
import scienceplots
plt.style.use(['science','ieee','no-latex'])

z1, t1, r1 = np.loadtxt("./results_omega_1_0_0.txt", unpack=True, skiprows=1)
z2, t2, r2 = np.loadtxt("./results_omega_0.3_0.7_0.txt", unpack=True, skiprows=1)
z3, t3, r3 = np.loadtxt("./results_omega_0.3_0_0.7.txt", unpack=True, skiprows=1)

plt.figure(dpi=600)
plt.plot(z1, r1, label="$(\Omega_m, \Omega_k, \Omega_\Lambda) = (1, 0, 0)$")
plt.plot(z2, r2, label="$(\Omega_m, \Omega_k, \Omega_\Lambda) = (0.3, 0.7, 0)$")
plt.plot(z3, r3, label="$(\Omega_m, \Omega_k, \Omega_\Lambda) = (0.3, 0, 0.7)$")
plt.xlabel("Redshift $z$")
plt.ylabel("Comoving distance $r(z)$ [Mpc]")
plt.legend()
plt.ylim(0, 11000)
plt.xlim(0,20)
plt.savefig("comoving_distance.pdf")

plt.figure(dpi=600)
plt.plot(z1, t1, label="$(\Omega_m, \Omega_k, \Omega_\Lambda) = (1, 0, 0)$")
plt.plot(z2, t2, label="$(\Omega_m, \Omega_k, \Omega_\Lambda) = (0.3, 0.7, 0)$")
plt.plot(z3, t3, label="$(\Omega_m, \Omega_k, \Omega_\Lambda) = (0.3, 0, 0.7)$")
plt.xlabel("Redshift $z$")
plt.ylabel("Cosmic look-back time $t(z)$ [Gyr]")
plt.legend()
plt.ylim(0, 14)
plt.xlim(0,20)
plt.savefig("cosmic_lookback_time.pdf")
