#include "Function.h"
Date InputDate(Date date)
{
	printf("Day: ");
	scanf_s("%d", &date.day);
	printf("Month: ");
	scanf_s("%d", &date.month);
	printf("Year: ");
	scanf_s("%d", &date.year);
	return date;
}
int CheckValidDate(Date date)
{
	if (date.day < 0 || date.month < 0 || date.month > 12)
	{
		return 0;
	}
	if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12)
	{
		if (date.day > 31)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
	{
		if (date.day > 30)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		if (date.year % 4 == 0 && date.year % 100 != 0 || date.year % 400 == 0)
		{
			if (date.day > 29)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			if (date.day > 28)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
	}
}
int CheckValidCode(PRODUCT new_product, PRODUCT product[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (new_product.code == product[i].code)
		{
			return 0;
		}
	}
	return 1;
}
void InputProduct(PRODUCT& product)
{
	printf("Code: ");
	getc(stdin);
	gets_s(product.code, 10);
	printf("Product: ");
	gets_s(product.name, 50);
	printf("Exp date: \n");
	product.exp = InputDate(product.exp);
	printf("Company: ");
	getc(stdin);
	gets_s(product.company, 50);
	printf("Year Produce: ");
	scanf_s("%d", &product.yearProduce);
}
void OutputProduct(PRODUCT product)
{
	printf("\nCode: %s", product.code);
	printf("\nProduct: %s", product.name);
	printf("\nExp date: %d/%d/%d", product.exp.day, product.exp.month, product.exp.year);
	printf("\nCompany: %s", product.company);
	printf("\nYear Produce: %d", product.yearProduce);
}
void ReadProductFromFile(char* filename, PRODUCT product[], int& i)
{
	FILE* fp;
	fp = fopen(filename, "rt");
	if (fp == NULL)
	{
		printf("cannot open file");
		return;
	}
	else
	{
		i = 0;
		char t[500];
		fgetc(fp);
		char* pch;
		while (fgets(t,500,fp) != NULL)
		{
			pch = strtok(t, "|" );
			strcpy(product[i].code, pch);
			pch = strtok(NULL, "|");
			strcpy(product[i].name, pch);
			pch = strtok(NULL, "/");
			product[i].exp.day = atoi(pch);
			pch = strtok(NULL, "/");
			product[i].exp.month = atoi(pch);
			pch = strtok(NULL, "|");
			product[i].exp.year = atoi(pch);
			pch = strtok(NULL, "|");
			strcpy(product[i].company, pch);
			pch = strtok(NULL, "\n");
			product[i].yearProduce = atoi(pch);
			i++;
		}
	}
	fclose(fp);
}
void AddProduct(char* filename, PRODUCT product)
{
	FILE* fp;
	fp = fopen(filename, "at");
	if (fp == NULL)
	{
		printf("cannot open file");
		return;
	}
	else
	{
		fprintf(fp, "\n%s|%s|%d/%d/%d|%s|%d", product.code, product.name, product.exp.day, product.exp.month, product.exp.year, product.company, product.yearProduce);
	}
	fclose(fp);
}
void DeleteProduct(PRODUCT product[], int &n, int k)
{
	if (k < 0 || k >= n)
	{
		return;
	}
	for (int i = k; i < n - 1; i++)
	{
		product[i] = product[i + 1];
	}
	n--;
}
void WriteProductToFile(char* filename, PRODUCT product[], int n)
{
	FILE* fp;
	fp = fopen(filename, "wt");
	if (fp == NULL)
	{
		printf("cannot open file");
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			fprintf(fp, "\n%s|%s|%d/%d/%d|%s|%d", product[i].code, product[i].name, product[i].exp.day, product[i].exp.month, product[i].exp.year, product[i].company, product[i].yearProduce);
		}
	}
	fclose(fp);
}
void FindProduct(char* filename, PRODUCT product[], char* keyword, int& flag)
{
	FILE* fp;
	fp = fopen(filename, "rt");
	if (fp == NULL)
	{
		printf("cannot open file");
		return;
	}
	else
	{
		char t[500];
		fgetc(fp);
		int i = 0;
		while (fgets(t, 500, fp) != NULL)
		{
			if (strstr(t, keyword) != NULL)
			{
				flag = 1;
				OutputProduct(product[i]);
			}
			i++;
		}
	}
	fclose(fp);
}
int CheckOldProduct(PRODUCT product)
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	if ((1900 + ltm->tm_year) > product.exp.year)
	{
		return 1;
	}
	else if (ltm->tm_mon + 1 > product.exp.month && (1900 + ltm->tm_year == product.exp.year))
	{
		return 1;
	}
	else if (ltm->tm_mday > product.exp.day&& ltm->tm_mon + 1 == product.exp.month && (1900 + ltm->tm_year == product.exp.year))
	{
		return 1;
	}
	return 0;
}