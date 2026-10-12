

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(void) {
    long long N;
    int thread_counts[] = {1, 2, 4, 8, 16, 32};
    int num_tests = 6;

    printf("Enter dataset size (100000, 1000000, or 10000000): ");

    if (scanf("%lld", &N) != 1 ||
        (N != 100000 && N != 1000000 && N != 10000000)) {
        printf("Invalid dataset size.\n");
        return 1;
    }

    long long *data = malloc((size_t)N * sizeof(long long));

    if (data == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (long long i = 0; i < N; i++) {
        data[i] = i + 1;
    }

    // Sequential calculation
    long long seq_sum = 0;
    double start = omp_get_wtime();

    for (long long i = 0; i < N; i++) {
        seq_sum += data[i];
    }

    double seq_time = omp_get_wtime() - start;
    double seq_avg = (double)seq_sum / N;

    printf("\n===== SEQUENTIAL RESULTS =====\n");
    printf("Dataset size : %lld\n", N);
    printf("Sum          : %lld\n", seq_sum);
    printf("Average      : %.2f\n", seq_avg);
    printf("Time         : %.6f seconds\n", seq_time);

    printf("\n===== PARALLEL RESULTS =====\n");
    printf("Threads,Sum,Average,Time,Speedup,Efficiency(%%)\n");

    for (int t = 0; t < num_tests; t++) {
        int threads = thread_counts[t];
        long long par_sum = 0;

        omp_set_num_threads(threads);
        start = omp_get_wtime();

        #pragma omp parallel for reduction(+:par_sum)
        for (long long i = 0; i < N; i++) {
            par_sum += data[i];
        }

        double par_time = omp_get_wtime() - start;
        double par_avg = (double)par_sum / N;
        double speedup = par_time > 0 ? seq_time / par_time : 0;
        double efficiency = speedup / threads * 100.0;

        printf("%d,%lld,%.2f,%.6f,%.4f,%.2f\n",
               threads, par_sum, par_avg, par_time,
               speedup, efficiency);
    }

    free(data);
    return 0;
}
