

int main() {
	signed char sc = 1;
	long l = 2;
	signed char* sp = &sc;
	long* dp = &l;
	*dp = (long) *sp;
	return 0;
}
