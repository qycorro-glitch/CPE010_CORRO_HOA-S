#include <iostream>
#include "Printer.h"

int main() {

   
    Printer printer(9);

    // Create print jobs
    Job job1(101, "Flux", 10);
    Job job2(102, "Kiel", 5);
    Job job3(103, "Uzi", 20);
    Job job4(104, "Win", 8);
    Job job5(105, "Aia", 6);
    Job job6(106, "Dos", 7);
    Job job7(107, "Sam", 12);
    Job job8(108, "Xia", 25);

    printer.AddJob(job1);
    printer.AddJob(job2);
    printer.AddJob(job3);
    printer.AddJob(job4);
    printer.AddJob(job5);
    printer.AddJob(job6);
    printer.AddJob(job7);
    printer.AddJob(job8);

  
    printer.ProcessJobs();

    return 0;
}