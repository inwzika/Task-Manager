#include <iostream>
using namespace std;

struct task
{
    char title[100];
    char sub[400];
    int imp;
    int day;
    int month;
    int year;

};

void sort (task** array , int size)
{
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size-1-i; ++j) {
            if (array[j]->imp>array[j+1]->imp)
                swap(array[j+1],array[j]);
        }
    }
}
void enqueue (task** &queue, int &n , task* data){
    n++;
    task** array = new task*[n];
    for (int i = 0 ; i < n-1 ; i++){
        array[i] = queue[i] ;
    }
    delete[] queue;
    queue = array;
    queue [n-1]= data;
}
task* new_task()
{
    task* t = new task;
    cout << "Title: ";
    scanf("%s", t->title);
    cout << "Subject: ";
    scanf("%s", t->sub);
    cout << "Importance: ";
    scanf("%d", &t->imp);
    cout << "Year: ";
    scanf("%d", &t->year);
    cout << "Month: ";
    scanf("%d", &t->month);
    cout << "Day: ";
    scanf("%d", &t->day);
    return t;
}
void view_task(task* x[] , int n){

    for (int i = 0;i < n;i++ ){
        cout << "title task :" << x[i]->title << endl;
        cout << "importance task :" << x[i]->imp << endl;
        cout << "deadline task :" << x[i]->year << '/' << x[i]->month << '/' <<  x[i]->day << endl;
    }

}
void view(task task){
    cout << "title task :" << task.title << endl;
    cout << "subject task :" << task.sub << endl;
    cout << "importance task :" << task.imp << endl;
    cout << "deadline task :" << task.year << '/' << task.month << '/' <<  task.day << endl;
}
int main()
{
    int size = 0;
    task** tasks = new task*[size];
    while(true){
        cout << "press number one to add task" << endl;
        cout << "press number two to view a task"<< endl;
        cout << "press number three to sort task"<< endl;
        cout << "press number four to view a task"<< endl;

        int x;
        cin >> x;

        switch (x)
        {
            case 4:
                cout << "Index? ";
                int y;
                cin >> y;
                view(*tasks[y]);
                break;
            case 3:
                sort(tasks,size);
                break;
            case 2:
                view_task(tasks,size);
                break;
            case 1:
                task* NEW = new_task();
                enqueue(tasks,size,NEW);
                break;

        }

    }

}