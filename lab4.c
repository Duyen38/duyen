#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Описание структуры MusicalComposition==========================================
struct MusicalCompisition
{
	char*name;
	char*author;
	int year;
	struct MusicalCompisition*next;
	struct MusicalCompisition*last;
};
typedef struct MusicalCompisition MusicalCompisition;

// Создание структуры MusicalComposition=============================================
MusicalCompisition* createMusicalComposition(char* name, char* author, int year)
{
	MusicalCompisition*element=(MusicalCompisition*)malloc(sizeof(MusicalCompisition));
	(element->name)=(MusicalCompisition*)malloc(strlen(name)*sizeof(MusicalCompisition));
	(element->author)=(MusicalCompisition*)malloc(strlen(author)*sizeof(MusicalCompisition));

	strcpy(element->name,name);
	strcpy(element->author,author);
	element->year=year;
	element->next=NULL;
	element->last=NULL;
	return element;
}

void push(MusicalCompisition* head,  MusicalCompisition* element);
// Функции для работы со списком MusicalComposition===================================================

MusicalCompisition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
	if(n==0)
		return NULL;
	int i=0;
	MusicalCompisition*head=createMusicalComposition(array_names[0],array_authors[0],array_years[0]);
	for(i=1;i<n;i++)
	{
		MusicalCompisition*element = createMusicalComposition(array_names[i],array_authors[i],array_years[i]);
		push(head,element);
	}
	return head;
}

// добавляет element  в конец списка musical_composition_list=================================

void push(MusicalCompisition* head,  MusicalCompisition* element)
{
	MusicalCompisition*p_element=head;//p_element-указатель нужен добавлять
	{
		while(p_element->next!=NULL)
		{
			p_element=p_element->next;
		}
		p_element->next=element;
		element->last=p_element;
	}
}

// удаляет элемент element списка, у которого значение name равно значению  name_for_remove=================

void removeEl(MusicalCompisition* head, char* name_for_remove)
{
	MusicalCompisition*element=head;
	MusicalCompisition*remove;//указатель нужен удалить

	while(element!=NULL)
	{
		if((strcmp(element->name,name_for_remove))==0)
		{
				remove=element;
				if(element->next!=NULL)
				{
					element->next->last=remove->last;
				}
				if(element->last!=NULL)
				{
					element->last->next=remove->next;
				}
				free(remove);
				return;
		}
		element=element->next;
	}
}

//возвращает количество элементов списка===========================
int count(MusicalCompisition* head)
{

	int k=0;
	while(head!=NULL)
	{
		k+=1;
		head=head->next;
	}
	return k;
}

//Выводит названия композиций=================================
void print_names(MusicalCompisition* head)
{
	MusicalCompisition*element=head;
	while(element!=NULL)
		{
			printf("%s\n",element->name);
			element=element->next;
		}
}


int main()
{
    int length;
    scanf("%d", &length);
	while(getchar()!='\n');
    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);

	int i;
    for (i=0;i<length;i++)
    {
        char name[80];
        char author[80];

        fgets(name, 80, stdin);
        fgets(author, 80, stdin);
        fscanf(stdin, "%d", &years[i]);
		while(getchar()!='\n');

        (*strstr(name,"\n"))=0;
        (*strstr(author,"\n"))=0;

        names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
        authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));

        strcpy(names[i], name);
        strcpy(authors[i], author);

    }
    MusicalCompisition* head = createMusicalCompositionList(names, authors, years, length);
    char name_for_push[80];
    char author_for_push[80];
    int year_for_push;

    char name_for_remove[80];

    fgets(name_for_push, 80, stdin);
    fgets(author_for_push, 80, stdin);
    fscanf(stdin, "%d\n", &year_for_push);
    (*strstr(name_for_push,"\n"))=0;
    (*strstr(author_for_push,"\n"))=0;

    MusicalCompisition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);

    fgets(name_for_remove, 80, stdin);
    (*strstr(name_for_remove,"\n"))=0;

    printf("%s %s %d\n", head->name, head->author, head->year);
    int k = count(head);

    printf("%d\n", k);
    push(head, element_for_push);

    k = count(head);
    printf("%d\n", k);

    removeEl(head, name_for_remove);
    print_names(head);

    k = count(head);
    printf("%d\n", k);


    for (i=0;i<length;i++){
        free(names[i]);
        free(authors[i]);
    }
    free(names);
    free(authors);
    free(years);

    return 0;
}
