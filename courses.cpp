void LoadCourse(const char* filename, Course &course)
{
	FILE* fp;
	fp = fopen(filename, "rt");
	if (fp == NULL)
	{
		printf("Cannot open file ! Have you closed your file yet ?");
		return;
	}
	else
	{
		fscanf_s(fp, "\nID: %d", &course.id);
		fscanf_s(fp, "\nCourse name: ");
		fgets(course.courseName, 30, fp);
		fscanf_s(fp, "Number of Students: %d", &course.nStudent);
		for (int i = 0; i < course.nStudent; i++)
		{
			fscanf_s(fp, "\nStudent ID : %ld", &course.student[i].id);
			fscanf_s(fp, "\nStudent name: ");
			fgets(course.student[i].fullname, 50, fp);
			fscanf_s(fp, "GPA: %f", &course.student[i].GPA);
			fprintf(fp, "\nStudent address: ");
			fgets(course.student[i].address, 70, fp);
			fscanf_s(fp, "Student birthday : ");
			fscanf_s(fp, "%d", &course.student[i].dob.day);
			fscanf_s(fp, "%d", &course.student[i].dob.month);
			fscanf_s(fp, "%d", &course.student[i].dob.year);
		}
		fscanf_s(fp, "\nCourse status: %d", &course.Status);
		fscanf_s(fp, "\nCourse Max Students : %d", &course.MaxStudent);
		fscanf_s(fp, "\nCourse Min Students : %d", &course.MinStudent);
		fclose(fp);
	}
}
void SaveCourse(const char* filename, Course course)
{
	FILE* fp;
	fp = fopen(filename, "wt");
	if (fp == NULL)
	{
		printf("Cannot open file ! Have you closed your file yet ?");
		return;
	}
	else
	{
		fprintf(fp, "\nID: %d", course.id);
		fprintf(fp, "\nCourse name: %s", course.courseName);
		for (int i = 0; i < course.nStudent; i++)
		{
			fprintf(fp, "\nStudent ID : %ld", course.student[i].id);
			fprintf(fp, "\nStudent name: %s",course.student[i].fullname);
			fprintf(fp, "\nGPA: %f", course.student[i].GPA);
			fprintf(fp, "\nStudent address: %s" ,course.student[i].address);
			fprintf(fp, "\nStudent birthday : %d %d %d", course.student[i].dob.day, course.student[i].dob.month, course.student[i].dob.year);
		}
		fprintf(fp, "\nCourse status: %d", course.Status);
		fprintf(fp, "\nCourse Max Students : %d", course.MaxStudent);
		fprintf(fp, "\nCourse Max Students : %d", course.MinStudent);
		fclose(fp);
	}
}
