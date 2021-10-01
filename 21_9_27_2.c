//µİ¹éÇó×Ö·û´®³¤¶È
#include<assert.h>
#include<stdio.h>
size_t my_strlen(const char* pa)
{
	assert(pa != NULL);
	if (*pa != '\0')
		return 1 + my_strlen(pa + 1);
	else
		return 0;
}
int main()
{
	char arr[100];
	gets(arr);
	printf("%d\n", my_strlen(arr));
	return 0;
}