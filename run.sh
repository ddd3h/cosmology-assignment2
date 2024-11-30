#!/bin/bash
set -e

echo "Running the program"
gcc calculation.cpp -o calculation -lm
echo "Calculating the output"
echo "This may take a moment, sorry!"
./calculation > specific_output.txt
echo "Output is saved in results_omega_*.txt"
echo "Output is saved in specific_output.txt"
echo "Creating virtual environment"
python3 -m venv cos_env
source cos_env/bin/activate
echo "Installing required packages"
pip install -r requirements.txt
echo "Running the python program to generate the plots"
python3 plot.py
echo "Deactivating the virtual environment"
deactivate
rm -rf cos_env
echo "Done"
echo "Bye!"
