import subprocess
import argparse

def parse_args():
  """
    Parse command arguments.
  """
  parser = argparse.ArgumentParser(description='Run executable')
  parser.add_argument('executable', help='Path to a executable file')
  parser.add_argument('input', help='Path to a file with input data')
  return parser.parse_args()
 

def main():
  args = parse_args()
  executable_path = args.executable
  input_path = args.input

  p = subprocess.Popen(executable_path, stdin=subprocess.PIPE, stdout=subprocess.PIPE, shell=True)

  with open(input_path) as f:
    input_data = f.read()

  (output, err) = p.communicate(input=input_data)
 
  p_status = p.wait()
  print(output)
  

if __name__ == "__main__":
  main()
