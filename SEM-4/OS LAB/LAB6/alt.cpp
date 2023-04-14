#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct process {
    int pid, art, bt, priority, ct, wt, tat, rt, start_time;
};

bool cmp_arrival_time(const process& a, const process& b) {
    return a.art < b.art;
}

bool cmp_priority(const process& a, const process& b) {
    return a.priority > b.priority;
}

void rr(process proc[], int n) {
    int comp = 0, curr_time = 0, sumWT = 0, sumTAT = 0;
    int tq;
    cout << "Enter the time quanta: ";
    cin >> tq;
    int isComp[n], bt_rem[n];
    cout << "Enter the process id, arrival time, and burst time: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> proc[i].pid >> proc[i].art >> proc[i].bt;
        isComp[i] = 0;
        bt_rem[i] = proc[i].bt;
    }
    sort(proc, proc + n, cmp_arrival_time);
    queue<process> ready;

    while (comp != n) {
        for (int i = 0; i < n; i++) {
            if (proc[i].art <= curr_time && isComp[i] == 0) {
                ready.push(proc[i]);
                isComp[i] = 1;
            }
        }

        if (ready.empty()) {
            curr_time++;
            continue;
        }

        process p = ready.front();
        ready.pop();

        if (bt_rem[p.pid] == p.bt) {
            p.start_time = max(curr_time, p.art);
            curr_time = p.start_time;
        }

        if (bt_rem[p.pid] - tq > 0) {
            bt_rem[p.pid] -= tq;
            curr_time += tq;
            ready.push(p);
        } else {
            curr_time += bt_rem[p.pid];
            p.ct = curr_time;
            p.tat = p.ct - p.art;
            p.wt = p.tat - p.bt;
            p.rt = p.start_time - p.art;
            sumTAT += p.tat;
            sumWT += p.wt;
            comp++;
            bt_rem[p.pid] = 0;
        }
    }

    cout << "PID\tART\tBT\tCT\tTAT\tWT\tRT\n";
    for (int i = 0; i < n; i++) {
        cout << proc[i].pid << "\t" << proc[i].art << "\t" << proc[i].bt << "\t" << proc[i].ct << "\t" << proc[i].tat << "\t" << proc[i].wt << "\t" << proc[i].rt << endl;
    }
    cout << "Average Waiting time: " << float(sumWT / n) << endl;
}

void srjf(process proc[], int n) {
    int comp = 0, curr_time = 0, sumWT = 0, sumTAT = 0;
    int bt_rem[n], isComp[n];
    cout << "Enter the process id, arrival time, burst time, and priority: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> proc[i].pid >> proc[i].art >> proc[i].bt >> proc[i].priority;
    }
    for (int i = 0; i < n; i++) {
                       ready.push(proc[i]);//push the process to the ready queue
                vis[i] = 1;
            }
        }
    }
    if(bt_rem[p.pid]>0){//if there are still some burst times left
        ready.push(proc[p.pid]);//push the process back to the queue
    }
}

cout<<"PID\t"<<"ART\t"<<"BT\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT"<<endl;
for(int i=0; i<n; i++){
    cout<<proc[i].pid<<"\t"<<proc[i].art<<"\t"<<proc[i].bt<<"\t"<<proc[i].ct<<"\t"<<proc[i].tat<<"\t"<<proc[i].wt<<"\t"<<proc[i].rt<<endl;
}
cout<<endl;
cout<<"Average Waiting time: "<<float(sumWT/n)<<endl;
}

void priority(){
int comp=0, curr_time=0;
int sumWT=0, sumTAT=0;
int n;
cout<<"Enter the number of processes: ";
cin>>n;
int isComp[n], bt_rem[n];
cout<<"Enter the process id, arrival time, burst time and priority:"<<endl;
for(int i=0; i<n; i++){
    cin>>proc[i].pid>>proc[i].art>>proc[i].bt>>proc[i].priority;
    isComp[i] = 0;
    bt_rem[i] = proc[i].bt;
}

while(comp!=n){
    int min_priority = INT_MAX;
    int min_idx = -1;

    for(int i=0; i<n; i++){
        if(proc[i].art<=curr_time && isComp[i]==0){
            if(proc[i].priority < min_priority){
                min_priority = proc[i].priority;
                min_idx = i;
            }
        }
    }

    if(min_idx == -1){
        curr_time++;
    }
    else{
        if(bt_rem[min_idx]==proc[min_idx].bt){
            proc[min_idx].start_time = curr_time;
        }

        bt_rem[min_idx]--;
        curr_time++;

        if(bt_rem[min_idx]==0){
            proc[min_idx].ct = curr_time;
            proc[min_idx].tat = proc[min_idx].ct-proc[min_idx].art;
            proc[min_idx].wt = proc[min_idx].tat-proc[min_idx].bt;
            proc[min_idx].rt = proc[min_idx].start_time-proc[min_idx].art;

            sumTAT += proc[min_idx].tat;
            sumWT +=proc[min_idx].wt;
            comp++;
            isComp[min_idx] = 1;
        }
    }
}

cout<<"PID\t"<<"ART\t"<<"BT\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT"<<endl;
for(int i=0; i<n; i++){
    cout<<proc[i].pid<<"\t"<<proc[i].art<<"\t"<<proc[i].bt<<"\t"<<proc[i].ct<<"\t"<<proc[i].tat<<"\t"<<proc[i].wt<<"\t"<<proc[i].rt<<endl;
}
cout<<endl;
cout<<"Average Waiting time: "<<float(sumWT/n)<<endl;
}

int main(){
int choice;
while(true){
cout<<"1. Shortest remaining time first"<<endl;
cout<<"2. Round Robin"<<endl;
cout<<"3. Priority Scheduling"<<endl;
cout<<"4. Exit"<<endl;
cout<<"Enter your choice: ";
cin>>choice;
switch(choice){
case 1:
srtf