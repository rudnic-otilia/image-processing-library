#include <stdio.h>
#include <stdlib.h>

// TODO Task 1
int ***flip_horizontal(int ***image, int N, int M) {
	for (int i = 0; i < N; i++) {
        for (int j = 0; j < M / 2; j++) {
			int *temp = image[i][j];
			image[i][j] = image[i][M - 1 - j];
            image[i][M - 1 - j] = temp;
            
        }
    }
	return image;
}

// TODO Task 2
int ***rotate_left(int ***image, int N, int M) {
	int ***m = (int ***)malloc(M * sizeof(int **));
    for (int i = 0; i < M; i++) {
        m[i] = (int **)malloc(N * sizeof(int *));
        for (int j = 0; j < N; j++) {
            m[i][j] = (int *)malloc(3 * sizeof(int));
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            m[M - 1 - j][i][0] = image[i][j][0];
            m[M - 1 - j][i][1] = image[i][j][1];
            m[M - 1 - j][i][2] = image[i][j][2];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            free(image[i][j]);
        }
		free(image[i]);
    }
	free(image);
	return m;
}

// TODO Task 3
int ***crop(int ***image, int N, int M, int x, int y, int h, int w) {
    int ***Crop = (int ***)malloc(h * sizeof(int **));
    for (int i = 0; i < h; i++) {
        Crop[i] = (int **)malloc(w * sizeof(int *));
        for (int j = 0; j < w; j++) {
            Crop[i][j] = (int *)malloc(3 * sizeof(int));
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            Crop[i][j][0] = image[i + y][j + x][0];
            Crop[i][j][1] = image[i + y][j + x][1];
            Crop[i][j][2] = image[i + y][j + x][2];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            free(image[i][j]);
        }
		free(image[i]);
    }
	free(image);
	return Crop;

}

// TODO Task 4
int ***extend(int ***image, int N, int M, int rows, int cols, int new_R, int new_G, int new_B) {
    int ***Extend = (int ***)malloc((N + 2*rows) * sizeof(int **));
    for (int i = 0; i < (N + 2*rows); i++) {
        Extend[i] = (int **)malloc((M + cols*2) * sizeof(int *));
        for (int j = 0; j < (M + cols*2); j++) {
            Extend[i][j] = (int *)malloc(3 * sizeof(int));
            Extend[i][j][0] = new_R;
            Extend[i][j][1] = new_G;
            Extend[i][j][2] = new_B;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            Extend[i + rows][j + cols][0] = image[i][j][0];
            Extend[i + rows][j + cols][1] = image[i][j][1];
            Extend[i + rows][j + cols][2] = image[i][j][2];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            free(image[i][j]);
        }
		free(image[i]);
    }
	free(image);
	return Extend;
}

// TODO Task 5
int ***paste(int ***image_dst, int N_dst, int M_dst, int *** image_src, int N_src, int M_src, int x, int y) {
    if (y + N_src > N_dst) {
    N_src = N_dst - y;
    }
    if (x + M_src > M_dst) {
    M_src = M_dst - x;
    }

    for (int i = 0; i < N_src; i++) {
    for (int j = 0; j < M_src; j++) {
        image_dst[i + y][j + x][0] = image_src[i][j][0];
        image_dst[i + y][j + x][1] = image_src[i][j][1];
        image_dst[i + y][j + x][2] = image_src[i][j][2];
    }
    }   

	return image_dst;
}

// TODO Task 6
int ***apply_filter(int ***image, int N, int M, float **filter, int filter_size) {
    int ***Filtered_image = (int ***)malloc(N * sizeof(int **));
    for (int i = 0; i < N; i++) {
        Filtered_image[i] = (int **)malloc(M * sizeof(int *));
        for (int j = 0; j < M; j++) {
            Filtered_image[i][j] = (int *)malloc(3 * sizeof(int));
        }
    }
    int centrare = filter_size/2;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            float r_prim = 0.0;
            float g_prim = 0.0;
            float b_prim = 0.0;
            for (int i_filter = 0; i_filter < filter_size; i_filter++){
                for (int j_filter = 0; j_filter < filter_size; j_filter++){
                    int fi = i - centrare + i_filter;
                    int fj = j - centrare + j_filter;
                    if ((fi >= 0) && (fi < N) && ((fj >= 0) && (fj < M))) {
                        r_prim = r_prim + filter[i_filter][j_filter] * image[fi][fj][0];
                        g_prim = g_prim + filter[i_filter][j_filter] * image[fi][fj][1];
                        b_prim = b_prim + filter[i_filter][j_filter] * image[fi][fj][2];
                    }
                }
            }
        Filtered_image[i][j][0] = (r_prim < 0) ? 0 : (r_prim > 255) ? 255 : (int)r_prim;
        Filtered_image[i][j][1] = (g_prim < 0) ? 0 : (g_prim > 255) ? 255 : (int)g_prim;
        Filtered_image[i][j][2] = (b_prim < 0) ? 0 : (b_prim > 255) ? 255 : (int)b_prim;
        }
    }
	return Filtered_image;
}
