int rand_in_range(int min, int max) {
	// TODO get a better algorithm bor uniform distribution
	return (rand() % (max - min)) + min;
}
