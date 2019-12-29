int isChar(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch < 'Z') || (ch >= '0' && ch <= '9');
}

struct WORD {
	char word[100];
	int so_lan_xh = 0;
};
int isInList(WORD list[], int n, char s[]) {
	for (int i = 0; i < n; i++) {
		if (strcmp(list[i].word, s))
			return i;
	}
	return -1;
}
int DemSoTuXuatHienNhieuNhat(char s[]) {
	WORD list[100];
	int n = 0;
	//strcat(s, " ");
	char word[100];
	int  j = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (isChar(s[i]))
		{
			word[j++] = s[i];
			if (!isChar(s[i + 1]))
			{
				word[j] = '\0';
				
				printf("%s\n", word);
				int k = isInList(list, n, word);
				if (k == -1) {
					strcpy(list[n].word, word);
					n++;
				}
				else {
					list[k].so_lan_xh++;
				}
				j = 0;
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++)
		if (max < list[i].so_lan_xh) max = list[i].so_lan_xh;
	return max;
}
