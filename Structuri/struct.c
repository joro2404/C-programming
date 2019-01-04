#include <stdio.h>
#include <string.h>

struct company_t{

	char name[128];
	//struct human_t ceo
	unsigned int employes;
	float budget;
}
;
struct teacher_t{

	char name [256];
    unsigned int age;
	char sex;
	char subject[64];
	unsigned int number_of_attended_classes;
	
	struct company_t company[10];
	unsigned int number_of_workplaces;
	
};

void print_company(struct company_t company){

	printf("%s %u %f\n", company.name, company.employes, company.budget);
}

void print_teacher (struct teacher_t teacher){

	printf("%s %c %u ", teacher.name, teacher.sex, teacher.age);
	printf("%s %u\n", teacher.subject, teacher.number_of_attended_classes);
	for (int i=0;i<teacher.number_of_workplaces;i++){	
		print_company(teacher.company[i]);
	}

}

struct teacher_t  add_company_to_teacher (struct teacher_t teacher, struct company_t compnay){

	teacher.company[teacher.number_of_workplaces++] = compnay;
	
	return teacher;
}

int main () {

	struct company_t elsys;

	strcpy(elsys.name, "Elsys");
	elsys.employes = 5;
	elsys.budget = 1000;

	struct teacher_t ee_teacher;

	strcpy(ee_teacher.name, "Penka");
	ee_teacher.sex = 'F';
	ee_teacher.age = 37;
	strcpy(ee_teacher.subject, "EE");
	ee_teacher.number_of_attended_classes = 36;
	ee_teacher.number_of_workplaces = 0;

	ee_teacher = add_copmany_to_teacher(ee_teacher,elsys);

	
	//printf("%s %u %f\n", elsys.name, elsys.employes, elsys.budget);

	print_teacher(ee_teacher);
	

	return 0;

}
