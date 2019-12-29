void DocSV(SinhVien sv[], int&n)
{
	FILE* fp;
	fp = fopen("INPUT.txt", "rt");
	if (fp == NULL)
	{
		printf("Cannot open file");
		return;
	}
	else
	{
		char t[500];
		int i = 0;
		while (fgets(t, 500, fp) != NULL)
		{
			char* pch;
			pch = strtok(t, "-()");
			sv[i].mssv = stoi(pch);
			pch = strtok(NULL, "-()");
			strcpy(sv[i].hoten, pch);
			pch = strtok(NULL, "-()");
			strcpy(sv[i].gioitinh, pch);
			pch = strtok(NULL, "-()");
			sv[i].diem = stof(pch);
			i++;
		}
		n = i;
	}
	fclose(fp);
}
