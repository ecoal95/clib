#ifndef __MATRIX_H
#define __MATRIX_H


#ifndef MATRIX_MAX_X
#define MATRIX_MAX_X 15
#endif

#ifndef MATRIX_MAX_Y
#define MATRIX_MAX_Y 15
#endif


/**
 * Leer matrices
 */
// Por ahora la única manera que sé de hacerla funcionar es definiendo los límites MATRIX_MAX_X, MATRIX_MAX_Y :(
void matrix_read_int(int matrix[MATRIX_MAX_X][MATRIX_MAX_Y], size_t fil, size_t col) {
	size_t i, j;
	for( i = 0; i < fil; i++ ) {
		for( j = 0; j < col; j++ ) {
			printf("[%d][%d]:", i, j);
			scanf("%d", &matrix[i][j]);
			utils_ib_clean();
		}
	}
}

void matrix_read_unsigned_int(unsigned int matrix[MATRIX_MAX_X][MATRIX_MAX_Y], size_t fil, size_t col) {
	size_t i, j;
	for( i = 0; i < fil; i++ ) {
		for( j = 0; j < col; j++ ) {
			printf("[%d][%d]:", i, j);
			scanf("%u", &matrix[i][j]);
			utils_ib_clean();
		}
	}
}


void matrix_read_char(char matrix[MATRIX_MAX_X][MATRIX_MAX_Y], size_t fil, size_t col) {
	size_t i, j;
	for( i = 0; i < fil; i++ ) {
		for( j = 0; j < col; j++ ) {
			printf("[%d][%d]:", i, j);
			scanf("%c", &matrix[i][j]);
			utils_ib_clean();
		}
	}
}

void matrix_read_float(float matrix[MATRIX_MAX_X][MATRIX_MAX_Y], size_t fil, size_t col) {
	size_t i, j;
	for( i = 0; i < fil; i++ ) {
		for( j = 0; j < col; j++ ) {
			printf("[%d][%d]:", i, j);
			scanf("%f", &matrix[i][j]);
			utils_ib_clean();
		}
	}
}

void matrix_read_double(double matrix[MATRIX_MAX_X][MATRIX_MAX_Y], size_t fil, size_t col) {
	size_t i, j;
	for( i = 0; i < fil; i++ ) {
		for( j = 0; j < col; j++ ) {
			printf("[%d][%d]:", i, j);
			scanf("%lf", &matrix[i][j]);
			utils_ib_clean();
		}
	}
}

/**
 * Mostrar vectores
 */
void array_print_int(int * array, size_t length) {
	size_t i = 0;
	printf("{");
	for( ; i < length; i++ ) {
		printf("%d", array[i]);
		if( i != length - 1 ) {
			printf(",");
		}
	}
	printf("}\n");
}
void array_print_char(char * array, size_t length) {
	size_t i = 0;
	printf("{");
	for( ; i < length; i++ ) {
		printf("%c", array[i]);
		if( i != length - 1 ) {
			printf(",");
		}
	}
	printf("}\n");
}
void array_print_float(float * array, size_t length) {
	size_t i = 0;
	printf("{");
	for( ; i < length; i++ ) {
		printf("%g", array[i]);
		if( i != length - 1 ) {
			printf(",");
		}
	}
	printf("}\n");
}
void array_print_double(double * array, size_t length) {
	size_t i = 0;
	printf("{");
	for( ; i < length; i++ ) {
		printf("%g", array[i]);
		if( i != length - 1 ) {
			printf(",");
		}
	}
	printf("}\n");
}


/**
 * Mostrar matrices
 */
void matrix_print_int(int matrix[MATRIX_MAX_X][MATRIX_MAX_Y], size_t x, size_t y) {
	size_t i, j;
	for( i = 0; i < x; i++ ) {
		printf("%3d | ", i);
		for( j = 0; j < y; j++ ) {
			printf("%5d   ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("------");
	for( j = 0; j < y; j++) {
		printf("--------");
	}
	printf("\n      ");
	for( j = 0; j < y; j++) {
		printf("%5d   ", j);
	}
	printf("\n");
}

void matrix_print_unsigned_int(unsigned int matrix[MATRIX_MAX_X][MATRIX_MAX_Y], size_t x, size_t y) {
	size_t i, j;
	for( i = 0; i < x; i++ ) {
		printf("%3d | ", i);
		for( j = 0; j < y; j++ ) {
			printf("%5d   ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("------");
	for( j = 0; j < y; j++) {
		printf("--------");
	}
	printf("\n      ");
	for( j = 0; j < y; j++) {
		printf("%5d   ", j);
	}
	printf("\n");
}

void matrix_print_char(char matrix[MATRIX_MAX_X][MATRIX_MAX_Y], size_t x, size_t y) {
	size_t i, j;
	for( i = 0; i < x; i++ ) {
		printf("%3d | ", i);
		for( j = 0; j < y; j++ ) {
			printf("%5c   ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("------");
	for( j = 0; j < y; j++) {
		printf("--------");
	}
	printf("\n      ");
	for( j = 0; j < y; j++) {
		printf("%5d   ", j);
	}
	printf("\n");
}

void matrix_print_float(float matrix[MATRIX_MAX_X][MATRIX_MAX_Y], size_t x, size_t y) {
	size_t i, j;
	for( i = 0; i < x; i++ ) {
		printf("%3d | ", i);
		for( j = 0; j < y; j++ ) {
			printf("%5g   ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("------");
	for( j = 0; j < y; j++) {
		printf("--------");
	}
	printf("\n      ");
	for( j = 0; j < y; j++) {
		printf("%5d   ", j);
	}
	printf("\n");
}

void matrix_print_double(double matrix[MATRIX_MAX_X][MATRIX_MAX_Y], size_t x, size_t y) {
	size_t i, j;
	for( i = 0; i < x; i++ ) {
		printf("%3d | ", i);
		for( j = 0; j < y; j++ ) {
			printf("%5g   ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("------");
	for( j = 0; j < y; j++) {
		printf("--------");
	}
	printf("\n      ");
	for( j = 0; j < y; j++) {
		printf("%5d   ", j);
	}
	printf("\n");
}

/**
 * Inicializar matrices
 */
void matrix_initialize_int(int matrix[MATRIX_MAX_X][MATRIX_MAX_Y], size_t x, size_t y, int val) {
	size_t i, j;
	for( i = 0; i < x; i++ ) {
		for(j = 0; j < y; j++) {
			matrix[i][j] = val;
		}
	}
}
void matrix_initialize_unsigned_int(unsigned int matrix[MATRIX_MAX_X][MATRIX_MAX_Y], size_t x, size_t y, unsigned int val) {
	size_t i, j;
	for( i = 0; i < x; i++ ) {
		for(j = 0; j < y; j++) {
			matrix[i][j] = val;
		}
	}
}
void matrix_initialize_char(char matrix[MATRIX_MAX_X][MATRIX_MAX_Y], size_t x, size_t y, char val) {
	size_t i, j;
	for( i = 0; i < x; i++ ) {
		for(j = 0; j < y; j++) {
			matrix[i][j] = val;
		}
	}
}
void matrix_initialize_float(float matrix[MATRIX_MAX_X][MATRIX_MAX_Y], size_t x, size_t y, float val) {
	size_t i, j;
	for( i = 0; i < x; i++ ) {
		for(j = 0; j < y; j++) {
			matrix[i][j] = val;
		}
	}
}
void matrix_initialize_double(double matrix[MATRIX_MAX_X][MATRIX_MAX_Y], size_t x, size_t y, double val) {
	size_t i, j;
	for( i = 0; i < x; i++ ) {
		for(j = 0; j < y; j++) {
			matrix[i][j] = val;
		}
	}
}
#endif
