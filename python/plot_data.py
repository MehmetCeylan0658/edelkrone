# -----------------------------------------------------------------------------
#
#
# -----------------------------------------------------------------------------
import sys
import csv
import matplotlib.pyplot as plt

# Very basic argument input check
if(len(sys.argv) < 2):
	print("What is the file name?")
	sys.exit(-1)

# Sanity check
print("File name: " + sys.argv[1])

# Create empty arrays for the log variables
tim = []
inp = []
filt0_out = []
filt1_out = []
filt2_out = []

# Read the input file
fp = open(sys.argv[1])
fp_content = fp.readlines()

# Parse the input file
fp_parsed = csv.reader(fp_content)
for row in fp_parsed:
	tim.append(float(row[0]))
	inp.append(float(row[1]))
	filt0_out.append(float(row[2]))
	filt1_out.append(float(row[3]))
	filt2_out.append(float(row[4]))

# Create new figure
plt.figure()

# Plot individual filter responses in subplots
plt.subplot(3,1,1)
plt.plot(tim, inp, 'k')
plt.plot(tim, filt0_out, 'r')
plt.xlabel("Time (ms)")
plt.ylabel("Value")

plt.subplot(3,1,2)
plt.plot(tim, inp, 'k')
plt.plot(tim, filt1_out, 'b')
plt.xlabel("Time (ms)")
plt.ylabel("Value")

plt.subplot(3,1,3)
plt.plot(tim, inp, 'k')
plt.plot(tim, filt2_out, 'g')
plt.xlabel("Time (ms)")
plt.ylabel("Value")

# Create another figure and plot all the responses in single figure
plt.figure()
plt.plot(tim, inp, 'k')
plt.plot(tim, filt0_out, 'r')
plt.plot(tim, filt1_out, 'b')
plt.plot(tim, filt2_out, 'g')
plt.xlabel("Time (ms)")
plt.ylabel("Value")

# Show the plots
plt.show()
