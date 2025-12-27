import subprocess
import os
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import sys
from matplotlib.colors import LinearSegmentedColormap
import time
from colorama import Fore, Style, init

# Initialize colorama
init(autoreset=True)

def run_command(command):
    """Run a command and return its output."""
    try:
        result = subprocess.run(command, shell=True, check=True, 
                              stdout=subprocess.PIPE, stderr=subprocess.PIPE, 
                              text=True)
        return result.stdout
    except subprocess.CalledProcessError as e:
        print(f"Error executing command: {e}")
        print(f"Error output: {e.stderr}")
        return None

def read_file(file_path):
    """Read a file and return its contents."""
    try:
        with open(file_path, 'r') as file:
            return file.read()
    except Exception as e:
        print(f"Error reading file: {e}")
        return None

def parse_array(line):
    """Parse an array from a line of input."""
    return [int(x) for x in line.split()]

def visualize_array(ax, array, title):
    """Visualize an array as a bar chart."""
    if not array:
        ax.text(0.5, 0.5, "No data available", ha='center', va='center')
        ax.set_title(title)
        return
    
    ax.bar(range(len(array)), array, color='skyblue', edgecolor='navy')
    ax.set_xticks(range(len(array)))
    ax.set_xticklabels([str(i) for i in range(len(array))])
    ax.set_title(title)
    ax.set_ylabel("Value")
    ax.set_xlabel("Index")
    
    # Add value labels on top of each bar
    for i, v in enumerate(array):
        ax.text(i, v + 0.1, str(v), ha='center')

def visualize_matrix(ax, matrix, title):
    """Visualize a matrix as a heatmap."""
    if not matrix or not matrix[0]:
        ax.text(0.5, 0.5, "No data available", ha='center', va='center')
        ax.set_title(title)
        return

    # Create custom colormap from blue to red
    colors = [(0, 0, 0.8), (1, 1, 1), (0.8, 0, 0)]
    cmap = LinearSegmentedColormap.from_list('custom_cmap', colors, N=256)
    
    # Find min and max for consistent scaling
    all_values = [val for row in matrix for val in row]
    if all_values:
        vmin = min(all_values)
        vmax = max(all_values)
        
        # If all values are the same, add a small range
        if vmin == vmax:
            vmin -= 0.5
            vmax += 0.5
    else:
        vmin, vmax = 0, 1

    # Create the heatmap
    im = ax.imshow(matrix, cmap=cmap, vmin=vmin, vmax=vmax)
    plt.colorbar(im, ax=ax)
    
    # Add text annotations
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            ax.text(j, i, str(matrix[i][j]), ha="center", va="center", 
                   color="black" if 0.2 < (matrix[i][j] - vmin) / (vmax - vmin) < 0.8 else "white")
    
    ax.set_title(title)
    ax.set_xticks(range(len(matrix[0])))
    ax.set_yticks(range(len(matrix)))

def parse_input(input_text):
    """Parse the input data based on the generator format."""
    lines = input_text.strip().split('\n')
    data = {"raw_input": input_text}
    
    if len(lines) >= 2:
        # Parse the first line as n (size of array)
        data["n"] = int(lines[0])
        
        # Parse the second line as the array
        if len(lines) > 1:
            data["array"] = parse_array(lines[1])
    
    return data

def parse_output(output_text):
    """Parse the output data."""
    lines = output_text.strip().split('\n')
    data = {"raw_output": output_text}
    
    # Try to parse as arrays, matrices, or just text
    arrays = []
    
    for line in lines:
        try:
            nums = parse_array(line)
            if nums:  # Only add non-empty arrays
                arrays.append(nums)
        except ValueError:
            # Not a valid array line, skip
            pass
    
    if arrays:
        if len(arrays) == 1:
            data["result_array"] = arrays[0]
        else:
            data["result_matrix"] = arrays
    
    return data

def visualize_test_case(input_data, solution_data, brute_data, test_num):
    """Create visualization for a single test case."""
    fig = plt.figure(figsize=(15, 10))
    fig.suptitle(f"Test Case {test_num}", fontsize=16)
    
    # Determine number of rows and columns based on what data we have
    num_rows = 3  # Input, Solution, Brute
    num_plots_per_row = 1
    
    # Check if we have matrix data in solution or brute
    has_matrix = ("result_matrix" in solution_data) or ("result_matrix" in brute_data)
    
    if has_matrix:
        num_plots_per_row = 2  # Separate plots for arrays and matrices
    
    plot_idx = 1
    
    # Plot input
    if "array" in input_data:
        ax = fig.add_subplot(num_rows, num_plots_per_row, plot_idx)
        visualize_array(ax, input_data["array"], "Input Array")
        plot_idx += 1
    
    # Plot solution output
    if "result_array" in solution_data:
        ax = fig.add_subplot(num_rows, num_plots_per_row, plot_idx)
        visualize_array(ax, solution_data["result_array"], "Solution Output")
        plot_idx += 1
    elif "result_matrix" in solution_data:
        ax = fig.add_subplot(num_rows, num_plots_per_row, plot_idx)
        visualize_matrix(ax, solution_data["result_matrix"], "Solution Output Matrix")
        plot_idx += 1
    
    # Plot brute output
    if "result_array" in brute_data:
        ax = fig.add_subplot(num_rows, num_plots_per_row, plot_idx)
        visualize_array(ax, brute_data["result_array"], "Brute Force Output")
        plot_idx += 1
    elif "result_matrix" in brute_data:
        ax = fig.add_subplot(num_rows, num_plots_per_row, plot_idx)
        visualize_matrix(ax, brute_data["result_matrix"], "Brute Force Output Matrix")
        plot_idx += 1
    
    # Add text output for comparison
    if "raw_output" in solution_data and "raw_output" in brute_data:
        ax = fig.add_subplot(num_rows, 1, num_rows)
        
        # Compare outputs
        sol_lines = solution_data["raw_output"].strip().split('\n')
        brute_lines = brute_data["raw_output"].strip().split('\n')
        
        comparison_text = "Output Comparison:\n\n"
        max_lines = max(len(sol_lines), len(brute_lines))
        
        for i in range(max_lines):
            sol_line = sol_lines[i] if i < len(sol_lines) else ""
            brute_line = brute_lines[i] if i < len(brute_lines) else ""
            
            if sol_line == brute_line:
                comparison_text += f"Line {i+1}: MATCH\n"
                comparison_text += f"  Solution: {sol_line}\n"
                comparison_text += f"  Brute:    {brute_line}\n\n"
            else:
                comparison_text += f"Line {i+1}: MISMATCH!\n"
                comparison_text += f"  Solution: {sol_line}\n"
                comparison_text += f"  Brute:    {brute_line}\n\n"
        
        ax.text(0.05, 0.95, comparison_text, ha='left', va='top', 
                fontsize=9, family='monospace', transform=ax.transAxes,
                verticalalignment='top', bbox=dict(boxstyle='round', facecolor='wheat', alpha=0.2))
        
        ax.axis('off')
    
    plt.tight_layout(rect=[0, 0.03, 1, 0.95])
    plt.savefig(f"test_case_{test_num}.png")
    plt.close(fig)

def main():
    num_tests = 100
    show_compilation = True
    
    # Check for command line arguments
    if len(sys.argv) > 1:
        try:
            num_tests = int(sys.argv[1])
        except ValueError:
            print("Invalid number of tests, using default (100)")
    
    if len(sys.argv) > 2:
        try:
            show_compilation = int(sys.argv[2]) == 1
        except ValueError:
            print("Invalid compilation flag, using default (True)")
    
    # Print welcome message
    print(Fore.CYAN + Style.BRIGHT + "===== Stress Test Visualizer =====")
    print(Fore.CYAN + f"Running {num_tests} tests" + Style.RESET_ALL)
    
    # Compile the files if needed
    if show_compilation:
        print(Fore.YELLOW + "Compiling solution, gen, brute..." + Style.RESET_ALL)
        run_command("g++ -std=c++17 gen.cpp -o gen")
        run_command("g++ -std=c++17 solution.cpp -o solution")
        run_command("g++ -std=c++17 brute.cpp -o brute")
        print(Fore.GREEN + "Compilation completed!" + Style.RESET_ALL)
        print()
    
    diff_found = False
    failing_test = 0
    
    for test_num in range(1, num_tests + 1):
        print(f"\rTesting: {test_num}/{num_tests}", end="")
        
        # Generate input
        run_command("gen > input.in")
        
        # Run solution and brute
        run_command("solution < input.in > output.out")
        run_command("brute < input.in > output2.out")
        
        # Check if outputs match
        result = run_command("fc output.out output2.out")
        if "FC: no differences encountered" not in str(result):
            diff_found = True
            failing_test = test_num
            break
    
    print()  # New line after progress output
    
    if diff_found:
        print(Fore.RED + Style.BRIGHT + f"[   Wrong answer on test {failing_test}   ]" + Style.RESET_ALL)
        print()
        
        # Read the input and outputs
        input_text = read_file("input.in")
        solution_output = read_file("output.out")
        brute_output = read_file("output2.out")
        
        # Print them to console
        print(Fore.CYAN + Style.BRIGHT + "Input:" + Style.RESET_ALL)
        print(Fore.MAGENTA + input_text + Style.RESET_ALL)
        print()
        
        print(Fore.CYAN + Style.BRIGHT + "Your output:" + Style.RESET_ALL)
        print(Fore.MAGENTA + solution_output + Style.RESET_ALL)
        print()
        
        print(Fore.CYAN + Style.BRIGHT + "Expected output:" + Style.RESET_ALL)
        print(Fore.MAGENTA + brute_output + Style.RESET_ALL)
        print()
        
        # Parse the data
        input_data = parse_input(input_text)
        solution_data = parse_output(solution_output)
        brute_data = parse_output(brute_output)
        
        # Create visualization
        print(Fore.YELLOW + "Creating visualization..." + Style.RESET_ALL)
        visualize_test_case(input_data, solution_data, brute_data, failing_test)
        print(Fore.GREEN + f"Visualization saved as test_case_{failing_test}.png" + Style.RESET_ALL)
    else:
        print(Fore.GREEN + Style.BRIGHT + "All testcases passed :D" + Style.RESET_ALL)
    
    # Clean up temporary files
    for file in ["input.in", "output.out", "output2.out", "gen.exe", "solution.exe", "brute.exe"]:
        if os.path.exists(file):
            os.remove(file)

if __name__ == "__main__":
    main()