#include <stdio.h>

typedef struct student_data {
    char name[26];
    char id[5];
    int exams[3];
    int hws[3];
    char grade;
} STUDENT_DATA;

int read_from_text_file(FILE* text_file, STUDENT_DATA* a_student)
{
    char buffer[100];
    int amount_read = 0;
    
    fgets(buffer, sizeof(buffer), text_file);
    amount_read = sscanf(buffer, "%s %s %d %d %d %d %d %d %c",
            (a_student->name), (a_student->id), &a_student->exams[0], 
            &a_student->exams[1], &a_student->exams[2], &a_student->hws[0],
            &a_student->hws[1], &a_student->hws[2], &(a_student->grade));
    
    
    /*
    amount_read += fscanf(text_file, "%s", (a_student->name));
    amount_read += fscanf(text_file, "%s", (a_student->id));
    for (int i = 0; i < 3; i++){
    amount_read += fscanf(text_file, "%d", &(a_student->exams[i]));
    amount_read += fscanf(text_file, "%d", &(a_student->hws[i]));
    }
    amount_read += fscanf(text_file, " %c", &(a_student->grade));    
    */
    if (amount_read == 9){
    return 1;
    } else {
    return 0;
    }
    /*
    faster way: use fgets to store into a buffer string;
    use sscanf to read from buffer in a single line
    */
}

int write_into_binary_file(FILE* binary_file, STUDENT_DATA* a_student)
{
    int amount_written;
    amount_written = fwrite(a_student, sizeof(STUDENT_DATA), 1, binary_file);
    if (amount_written != 1) {
        return 0;
    } else {
        return 1;
    }
}

int read_from_binary_file(FILE* binary_file, STUDENT_DATA* a_student){
  //  int buffer[sizeof(STUDENT_DATA)*10];
    int amount_read = fread(a_student, sizeof(STUDENT_DATA), 1, binary_file);
    if (amount_read != 1){
        return 0;
    } else {
        return 1;
    }
}
int write_into_text_file(FILE* text_file, STUDENT_DATA* a_student){
    int amount_written = fprintf(text_file, "%-26s %-5s %3d %3d %3d %3d %3d %3d %c\n",
            (a_student->name), (a_student->id), a_student->exams[0], 
            a_student->exams[1], a_student->exams[2], a_student->hws[0],
            a_student->hws[1], a_student->hws[2], a_student->grade);
    
    if (amount_written != 9){
        return 0;
    } else {
        return 1;
    }
    
}

int main(){
    
    
    STUDENT_DATA a_student;
    FILE* text_file;
    FILE* binary_file;
    if (!(text_file = fopen("data.txt", "r"))){
        return 0;
    } else if (!(binary_file = fopen("binary.dat", "wb"))){
        return 0;
    }
    
    while (read_from_text_file(text_file, &a_student)){
        write_into_binary_file(binary_file, &a_student);
    }

    fclose(text_file);
    fclose(binary_file);
    
    if (!(text_file = fopen("data2.txt", "w"))){
        return 0;
    } else if (!(binary_file = fopen("binary.dat", "rb"))){
        return 0;
    }
    
    while (read_from_binary_file(binary_file, &a_student)){
        write_into_text_file(text_file, &a_student);
    }

    printf("name: %s, id: %s, grade 1: %d, grade: %c \n", a_student.name, a_student.id, a_student.exams[0], a_student.grade);
    fclose(text_file);
    fclose(binary_file);
    return 0;
}