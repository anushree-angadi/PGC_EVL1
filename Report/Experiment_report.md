
# Experiment Report: Parallel Sum and Average Using OpenMP

## 1. Aim

To implement sequential and OpenMP parallel sum and average calculations and evaluate the effect of dataset size and thread count on execution performance.

## 2. Software Requirements

- Ubuntu
- GCC compiler
- OpenMP support
- Python 3 and Matplotlib for plotting

## 3. Algorithm

### Sequential algorithm

1. Generate the dataset.
2. Initialize the sum to zero.
3. Add each element to the sum using a sequential loop.
4. Calculate the average by dividing the sum by the dataset size.
5. Record the execution time.

### Parallel algorithm

1. Generate the dataset.
2. Initialize the parallel sum.
3. Use OpenMP `parallel for` to distribute loop iterations among threads.
4. Use the `reduction` clause to combine partial sums.
5. Calculate the average and record the execution time.

## 4. Experimental Setup

Dataset sizes: 100,000; 1,000,000; 10,000,000.

Thread counts: 1, 2, 4, 8, 16, 32.

## 5. Performance Metrics

Speedup = Sequential time / Parallel time.

Efficiency (%) = Speedup / Number of threads × 100.

## 6. Results and Discussion

For 10,000,000 elements, the best observed result was obtained with four threads. The sequential time was 0.006908 seconds, while the parallel time was 0.002608 seconds. The corresponding speedup was approximately 2.65×, with 66.21% efficiency.

The measurements also show that increasing the thread count does not always reduce execution time. Thread-management overhead, available virtual CPUs, memory access, and measurement variation can influence the results.

## 7. Limitations

The recorded measurements are preliminary single-run timings. Multiple repetitions and averaged execution times are recommended for a more reliable performance comparison.

## 8. Conclusion

The experiment demonstrates the use of OpenMP to parallelize a sum calculation and compares sequential and parallel performance for different dataset sizes and thread counts. Correctness was verified by matching the computed sums and averages to their expected values.
