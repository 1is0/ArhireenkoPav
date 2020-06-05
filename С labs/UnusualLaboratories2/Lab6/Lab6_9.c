/* Эта программа выводит на экран двоичное дерево. */

#include <stdlib.h>
#include <stdio.h>

struct tree {
    int info;
    struct tree* left;
    struct tree* right;
};

struct tree* root; /* начальная вершина дерева */
struct tree* stree(struct tree* root,
    struct tree* r, int info, int count);
void prin(struct tree* root, int tabc);

int main(void) {

        FILE* fp1;
        fopen_s(&fp1, "kik3.txt", "r");
        if (fp1 == NULL) {
            puts("Cannot open file.");
            return 0;
        };

        int* mas = (int*)malloc(7 * sizeof(int));
        char* y = (char*)malloc(10 * sizeof(char));

        char** fz1 = (char**)malloc(7 * sizeof(char*));
        if (!fz1) return 1;
        for (int i = 0; i < 7; i++) {
            fz1[i] = (char*)malloc(80 * sizeof(char));
        }

        for (int i = 0; i < 7; i++)
        {
            fgets(fz1[i], 10, fp1);
        }

        for (int i = 0; i < 7; i++) {
            for(int j = 0; j<8; j++){
                y[j] = fz1[i][j];
            }
            mas[i] = atoi(y);
        }

    char* s = (char*)malloc(80 * sizeof(char));

    root = NULL;  /* инициализация корня дерева */

    for (int i = 0; i < 7; i++) {
        int pool = 1, loop = 0;
        int n = 0; //количество битов в числе
        while (mas[i] / pool) {
            n++;
            pool *= 10;
        }
        for (int j = 0; j < n; j++) {
            pool /= 10;
            loop = mas[i] / pool;
            root = stree(root, root, loop, 1);
        }
    }

    prin(root, 0);

    return 0;
}

struct tree* stree(
    struct tree* root,
    struct tree* r,
    int info,
    int count)
{
    int pool = 1, loop = 0;
    int n = 0; //количество битов в числе
    while (info/pool) {
        n++;
        pool *= 10;
    }
    for (int j = 0; j < count; j++) {
        pool /= 10;
        loop = info / pool;
    }
    int kiker = loop % 10;
    count++;
    if (!r) {
        r = (struct tree*) malloc(sizeof(struct tree));
        if (!r) {
            printf("Не хватает памяти\n");
            exit(0);
        }
        r->left = NULL;
        r->right = NULL;
        r->info = info;
        if (!root) return r; /* первый вход */
        if (kiker == 0) 
            root->left = r;
        else 
            root->right = r;
        return r;
    }
    if (info == r->info) return r;
    pool /= 10;
    loop = info / pool;
    kiker = loop % 10;

    if (kiker == 0) {
        stree(r, r->left, info, count);
    }
    else {
        stree(r, r->right, info, count);
    }

    return root;
}

void prin(struct tree* r, int tabc)
{
    if (!r) return;

    tabc++; //Иначе увеличим счетчик рекурсивно вызванных процедур
 //Который будет считать нам отступы для красивого вывода

    prin(r->left, tabc); //Выведем ветку и ее подветки слева

    for (int i = 0; i < tabc; i++) printf(" "); //Потом отступы
    printf("%d\n",r->info);//Данные этой ветки


    prin(r->right, tabc); //И ветки, что справа

    tabc--; //После уменьшим кол-во отступов
    return;
}