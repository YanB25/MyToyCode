 #include <cstdio>
char * convertDecimalToHex(int value) {
  char ret[20];
  sprintf(ret, "%x", value);
  return ret;
}

void convertDecimalToHex(int value, char *s) {
  s = convertDecimalToHex(value);
}
int main() {
	char* tmp = convertDecimalToHex(100);
	printf("%s", tmp);
	return 0;
}
