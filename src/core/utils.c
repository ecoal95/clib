/**
 * Clean the input buffer
 * We can fflush(stdin) on windows, but it apparently doesn't work on ubuntu
 */
void utils_ib_clean() {
	char c;
	while((c = getchar()) != '\n' && c != EOF) /* Cuerpo del loop vacío, símplemente descartamos caracteres */;
}


/**
 * Pause the program until a key is pressed, but sending a message before
 */
void utils_pause() {
	printf("\nPulsa una tecla para continuar...\n");
	utils_ib_clean();
	getchar();
}
