#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <sys/time.h>
int* createMatrSinglSize(int* mas,int sqrtSize);
int* AlgoritmShtrassen(int* a,int* b,int size);
void splitMatrix(int* a,int* a11,int* a12,int* a21,int* a22,int size);
int* collectMatrix(int* a11,int* a12,int* a21,int* a22,int size);
int* subtraction(int*a,int*b,int size);
int* summation(int*a,int*b,int size);
int* multiply(int*a,int*b,int size);
_Bool step2(int n);
int oprnumb(int n);
void print(int* mas,int sqrtSize);
int * createnewmatr(int n);

int *a1,*b1;
int *a,*b;
int newSize;
int sqrtSize_a,sqrtSize_b;

int main()
{
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    printf("%s\n\n","Алготм перемножения матриц методом Штрассена");
    int menu;
    while(TRUE){
        printf("%s\n","Выберите один из пунктов");
        printf("%s\n","1-Задать матрицы");
        printf("%s\n","2-Перемножить матрицы и отобразить");
        printf("%s\n","3-Отобразить матрицы");
        printf("%s\n","0-Выход");
        if((scanf("%d",&menu)==0)||(menu<0)||(menu>3)){
                printf("%s\n","Некорректный ввод");
                if(getchar()!='\n')
                while(getchar()!='\n');
                continue;
            }
        if(getchar()!='\n'){
            printf("%s\n","Некорректный ввод");
            while(getchar()!='\n');
            continue;
        }
        switch(menu){
        case 1:
            zadatMatrix();
            break;
        case 2:
            multiplicationAndShow();
            break;
        case 3:
            showMatrixs();
            break;
        case 0:
            return;
        }
    }
    return 0;
}

void showMatrixs(){
    if(a1==NULL&&b1==NULL) {printf("%s\n","Матрицы не созданы");return;}
    int menu;
    while(TRUE){
        printf("%s\n","1-Отобразить 1 матрицу");
        printf("%s\n","2-Отобразить 2 матрицу");
        printf("%s\n","0-Выйти");
        if((scanf("%d",&menu)==0)||(menu<0)||(menu>2)){
            printf("%s\n","Некорректный ввод");
            if(getchar()!='\n')
            while(getchar()!='\n');
            continue;
        }
        if(getchar()!='\n'){
            printf("%s\n","Некорректный ввод");
            while(getchar()!='\n');
            continue;
        }
        switch(menu){
            case 1:
                if(a1==NULL) printf("%s\n","Матрица не создана");
                else {
                    printf("%s\n","A");
                    print(a1,sqrtSize_a);
                }
                break;
            case 2:
                if(b1==NULL) printf("%s\n","Матрица не создана");
                else {
                    printf("%s\n","B");
                    print(b1,sqrtSize_b);
                }
                break;
            case 0:
                return;
        }
    }
}

void zadatMatrix(){
    int menu;
    while(TRUE){
        printf("%s\n","1-Задать 1 матрицу");
        printf("%s\n","2-Задать 2 матрицу");
        printf("%s\n","0-Выйти");
        if((scanf("%d",&menu)==0)||(menu<0)||(menu>2)){
            printf("%s\n","Некорректный ввод");
            if(getchar()!='\n')
            while(getchar()!='\n');
            continue;
        }
        if(getchar()!='\n'){
            printf("%s\n","Некорректный ввод");
            while(getchar()!='\n');
            continue;
        }
        switch(menu){
            case 1:
                zadatMatrixs(1);
                break;
            case 2:
                zadatMatrixs(2);
                break;
            case 0:
                return;
        }
    }
}

void zadatMatrixs(int chois){
    int value,rows,colums;
    printf("%s\n","Введите кол-во строк");
    while(TRUE){
        if((scanf("%d",&rows)==0)||(rows<=0)){
            printf("%s\n","Некорректный ввод, повторите ввод");
            if(getchar()!='\n')
            while(getchar()!='\n');
            continue;
        }
        if(getchar()!='\n'){
            printf("%s\n","Некорректный ввод, повторите ввод");
            while(getchar()!='\n');
            continue;
        }
        break;
    }
    printf("%s\n","Введите кол-во столбцов");
    while(TRUE){
        if((scanf("%d",&colums)==0)||(colums<=0)){
            printf("%s\n","Некорректный ввод, повторите ввод");
            if(getchar()!='\n')
            while(getchar()!='\n');
            continue;
        }
        if(getchar()!='\n'){
            printf("%s\n","Некорректный ввод, повторите ввод");
            while(getchar()!='\n');
            continue;
        }
        break;
    }
    if(rows!=colums) {
        printf("%s\n","Матрица не квадратная. Алгоритм работает на квадратных матрицах.Повторите ввод");
        zadatMatrixs(chois);
        return;
    }
    /*сoздание матрицы*/
    if(chois==1){
        a1=malloc(sizeof(int)*colums*rows);
        sqrtSize_a=rows;
    }
    else{
        b1=malloc(sizeof(int)*colums*rows);
        sqrtSize_b=rows;
    }
    /*заполнение матрицы*/
    int i,j;
    for(i=0;i<rows;i++)
        for(j=0;j<colums;j++){
            printf("[%d][%d]",i+1,j+1);
            while(TRUE){
                if((scanf("%d",&value)==0)){
                printf("%s\n","Некорректный ввод, повторите ввод");
                if(getchar()!='\n')
                while(getchar()!='\n');
                continue;
            }
            if(getchar()!='\n'){
                printf("%s\n","Некорректный ввод, повторите ввод");
                while(getchar()!='\n');
                continue;
            }
            break;
            }
            if(chois==1)
            *(a1+i*rows+j)=value;
            else *(b1+i*rows+j)=value;
        }
}

void multiplicationAndShow(){
    int menu;
    int size;
    while(TRUE){
        printf("%s\n","1-Сгенерить матрицы и перемножить");
        printf("%s\n","2-Перемножить уже существующие");
        printf("%s\n","0-Выйти");
        if((scanf("%d",&menu)==0)||(menu<0)||(menu>2)){
                printf("%s\n","Некорректный ввод");
                if(getchar()!='\n')
                while(getchar()!='\n');
                continue;
            }
            if(getchar()!='\n'){
                printf("%s\n","Некорректный ввод");
                while(getchar()!='\n');
                continue;
            }
        switch(menu){
        case 1:
            printf("%s\n","Введите размер умножаемых матриц");
            while(TRUE){
                if((scanf("%d",&size)==0)||(size<=0)){
                printf("%s\n","Некорректный ввод, повторите ввод");
                if(getchar()!='\n')
                while(getchar()!='\n');
                continue;
            }
                if(getchar()!='\n'){
                printf("%s\n","Некорректный ввод, повторите ввод");
                while(getchar()!='\n');
                continue;
                }
                break;
            }
            a=createnewmatr(size);
            b=createnewmatr(size);
            if(!step2(size)) size=oprnumb(size);
            printf("\nA\n");
            print(a,size);
            printf("\nB\n");
            print(b,size);
            printf("\n%s\n","Result");
            print(AlgoritmShtrassen(a,b,size*size),size);
            putchar('\n');
            break;
        case 2:
            if(a1==NULL||b1==NULL)
                printf("%s\n","Одна из матриц не создана или обе");
            else if(sqrtSize_a!=sqrtSize_b)
                printf("%s\n","Данные матрицы не можно перемножить ибо кл-во строк в первой не равно кол-ву столбцов во второй и наоборот");
            else{
            a=createMatrSinglSize(a1,sqrtSize_a);
            b=createMatrSinglSize(b1,sqrtSize_b);
            print(AlgoritmShtrassen(a,b,newSize*newSize),newSize);
            }
            break;
        case 0:
            return;
        }
    }

}

int* createMatrSinglSize(int* mas,int sqrtSize){
    int sizemas;
    if(step2(sqrtSize)){
        newSize=sqrtSize;
        return mas;
    }
    else {
        sizemas=oprnumb(sqrtSize);
        newSize=sizemas;
    }
    int *res=malloc(sizeof(int)*sizemas*sizemas);
    int i=0,j=0;
    for(i=0;i<sizemas;i++)
        for(j=0;j<sizemas;j++)
        if(i>=sqrtSize||j>=sqrtSize)
            *(res+(i*sizemas+j))=0;
        else
            *(res+(i*sizemas+j))=*(mas+i*sqrtSize+j);
    return res;
}

int * createnewmatr(int n){
    int sizemas;
    if(step2(n))
        sizemas=n;
    else sizemas=oprnumb(n);
    int *res=malloc(sizeof(int)*sizemas*sizemas);
    int i=0,j=0;
    for(i=0;i<sizemas;i++)
        for(j=0;j<sizemas;j++)
        if(i>=n||j>=n)
            *(res+(i*sizemas+j))=0;
        else
            *(res+(i*sizemas+j))=rand()%100;
    return res;
}

int* AlgoritmShtrassen(int* a,int* b,int size){
if(size<=4)
    return multiply(a,b,size);
int* a11=malloc(sizeof(int)*(size/4));
int* a12=malloc(sizeof(int)*(size/4));
int* a21=malloc(sizeof(int)*(size/4));
int* a22=malloc(sizeof(int)*(size/4));

int* b11=malloc(sizeof(int)*(size/4));
int* b12=malloc(sizeof(int)*(size/4));
int* b21=malloc(sizeof(int)*(size/4));
int* b22=malloc(sizeof(int)*(size/4));

splitMatrix(a,a11,a12,a21,a22,size);
splitMatrix(b,b11,b12,b21,b22,size);

int* p1=AlgoritmShtrassen(summation(a11,a22,size/4),summation(b11,b22,size/4),size/4);
int* p2=AlgoritmShtrassen(summation(a21,a22,size/4),b11,size/4);
int* p3=AlgoritmShtrassen(a11,subtraction(b12,b22,size/4),size/4);
int* p4=AlgoritmShtrassen(a22,subtraction(b21,b11,size/4),size/4);
int* p5=AlgoritmShtrassen(summation(a11,a12,size/4),b22,size/4);
int* p6=AlgoritmShtrassen(subtraction(a21,a11,size/4),summation(b11,b12,size/4),size/4);
int* p7=AlgoritmShtrassen(subtraction(a12,a22,size/4),summation(b21,b22,size/4),size/4);

int* c11=summation(summation(p1,p4,size/4),subtraction(p7,p5,size/4),size/4);
int* c12=summation(p3,p5,size/4);
int* c21=summation(p2,p4,size/4);
int* c22=summation(subtraction(p1,p2,size/4),summation(p3,p6,size/4),size/4);

return collectMatrix(c11,c12,c21,c22,size/4);
}

void splitMatrix(int* a,int* a11,int* a12,int* a21,int* a22,int size)
{
    int i,j;
    for(i=0;i<(int)sqrt((double)size)/2;i++)
        for(j=0;j<(int)sqrt((double)size)/2;j++)
        *(a11+i*((int)sqrt((double)size)/2)+j)=*(a+i*(int)sqrt((double)size)+j);
    for(i=0;i<(int)sqrt((double)size)/2;i++)
        for(j=((int)sqrt((double)size)/2);j<(int)sqrt((double)size);j++)
        *(a12+i*((int)sqrt((double)size)/2)+j-((int)sqrt((double)size)/2))=*(a+i*(int)sqrt((double)size)+j);
    for(i=((int)sqrt((double)size)/2);i<(int)sqrt((double)size);i++)
        for(j=0;j<(int)sqrt((double)size)/2;j++)
        *(a21+(i-((int)sqrt((double)size)/2))*((int)sqrt((double)size)/2)+j)=*(a+i*(int)sqrt((double)size)+j);
    for(i=((int)sqrt((double)size)/2);i<(int)sqrt((double)size);i++)
        for(j=((int)sqrt((double)size)/2);j<(int)sqrt((double)size);j++)
           *(a22+(i-((int)sqrt((double)size)/2))*((int)sqrt((double)size)/2)+j-((int)sqrt((double)size)/2))=*(a+i*(int)sqrt((double)size)+j);
}

int* collectMatrix(int* a11,int* a12,int* a21,int* a22,int size)
{
    int i,j,newsize=size*4;
    int* result=malloc(newsize*sizeof(int));
    for(i=0;i<(int)sqrt((double)newsize)/2;i++)
        for(j=0;j<(int)sqrt((double)newsize)/2;j++)
        *(result+i*(int)sqrt((double)newsize)+j)=*(a11+i*(int)sqrt((double)size)+j);
    for(i=0;i<(int)sqrt((double)newsize)/2;i++)
        for(j=((int)sqrt((double)newsize)/2);j<(int)sqrt((double)newsize);j++)
        *(result+i*(int)sqrt((double)newsize)+j)=*(a12+i*(int)sqrt((double)size)+j-((int)sqrt((double)newsize)/2));
    for(i=((int)sqrt((double)newsize)/2);i<(int)sqrt((double)newsize);i++)
        for(j=0;j<(int)sqrt((double)newsize)/2;j++)
        *(result+i*(int)sqrt((double)newsize)+j)=*(a21+(i-((int)sqrt((double)newsize)/2))*((int)sqrt((double)size))+j);
    for(i=((int)sqrt((double)newsize)/2);i<(int)sqrt((double)newsize);i++)
        for(j=((int)sqrt((double)newsize)/2);j<(int)sqrt((double)newsize);j++)
           *(result+i*(int)sqrt((double)newsize)+j)=*(a22+(i-((int)sqrt((double)newsize)/2))*((int)sqrt((double)size))+j-((int)sqrt((double)newsize)/2));
    return result;
}

int* summation(int*a,int*b,int size){
    int* result=malloc(size*sizeof(int));
    int i,j;
    for(i=0;i<(int)sqrt((double)size);i++)
        for(j=0;j<(int)sqrt((double)size);j++)
        *(result+i*(int)sqrt((double)size)+j)=*(a+i*(int)sqrt((double)size)+j)+*(b+i*(int)sqrt((double)size)+j);
    return result;
}

int* subtraction(int*a,int*b,int size)
{
    int* result=malloc(size*sizeof(int));
    int i,j;
    for(i=0;i<(int)sqrt((double)size);i++)
        for(j=0;j<(int)sqrt((double)size);j++)
        *(result+i*(int)sqrt((double)size)+j)=*(a+i*(int)sqrt((double)size)+j)-*(b+i*(int)sqrt((double)size)+j);
    return result;
}

int* multiply(int*a,int*b,int size)
{
    int* result=malloc(size*sizeof(int));
    int i,j,k;
    for(i=0;i<(int)sqrt((double)size);i++)
        for(j=0;j<(int)sqrt((double)size);j++){
            *(result+i*(int)sqrt((double)size)+j)=0;
            for(k=0;k<(int)sqrt((double)size);k++)
            *(result+i*(int)sqrt((double)size)+j)+=*(a+i*(int)sqrt((double)size)+k)**(b+k*(int)sqrt((double)size)+j);
        }
    return result;
}
_Bool step2(int n)
{
    if(n==1)
        return 1;
    if(n<1)
        return 0;
    return ((n&(n-1))==0);
}

int oprnumb(int n)
{
    int count=0,an=n;
    while(an)
    {
        count++;
        an>>=1;
    }
    n>>=(count-1);
    n<<=count;
    return n;
}

void print(int* mas,int sqrtSize){
    int i,j;
    for(i=0;i<sqrtSize;i++)
    {
        for(j=0;j<sqrtSize;j++)
            printf("%d\t",*(mas+i*sqrtSize+j));
        putchar('\n');
    }
}


/*litvinova.virt@gmail.com*/
