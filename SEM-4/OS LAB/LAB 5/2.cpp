#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

using namespace std;

int main()
{
    char a[5][20], temp[20];
    int i, j, status;

    cout << "Enter the 5 strings" << endl;
    for (int i = 0; i < 5; i++)
        cin >> a[i];

    pid_t pid;
    pid = fork();

    if (pid == 0) {
        cout << "In child process" << endl;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4 - i; j++) {
                if (strcmp(a[j], a[j + 1]) > 0) {
                    strcpy(temp, a[j]);
                    strcpy(a[j], a[j + 1]);
                    strcpy(a[j + 1], temp);
                }
            }
        }
        cout << "The list in sorted order are" << endl;
        for (i = 0; i < 5; i++)
            cout << a[i] << endl;
    }
    else if (pid > 0) {
        wait(&status);
        if (WIFEXITED(status))
            cout << "Child returned" << endl;

        cout << "In parents process" << endl;
        cout << "The list in unsorted order are" << endl;
        for (i = 0; i < 5; i++)
            cout << a[i] << endl;
    }

    return 0;
}
