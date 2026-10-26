#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <string>


class Job {
private:
    int jobID;
    std::string userN;
    int pages;

public:
    Job() {
        jobID = 0;
        getUserN= "";
        pages = 0;
    }

    Job(int id, std::string name, int numPages) {
        jobID = id;
        userN = name;
        pages = numPages;
    }

    int getJobID() {
        return jobID;
    }

    std::string getUserN() {
        return userN;
    }

    int getPages() {
        return pages;
    }

    void displayJob() {
        std::cout << "Job ID: " << jobID << std::endl;
        std::cout << "User: " << userN << std::endl;
        std::cout << "Pages: " << pages << std::endl;
    }
};



template <typename T>
class queueArr {
private:
    T* q_array;
    size_t q_capacity;
    size_t q_size;
    int q_front;
    int q_back;

public:
    queueArr(size_t capacity) {
        q_capacity = capacity;
        q_size = 0;
        q_front = 0;
        q_back = -1;

        q_array = new T[q_capacity];
    }

    ~queueArr() {
        delete[] q_array;
    }

    bool Empty() {
        return q_size == 0;
    }

    bool Full() {
        return q_size == q_capacity;
    }

    size_t Size() {
        return q_size;
    }

    T Front() {
        if (Empty()) {
            std::cout << "Queue is empty." << std::endl;
            return T();
        }

        return q_array[q_front];
    }

    T Back() {
        if (Empty()) {
            std::cout << "Queue is empty." << std::endl;
            return T();
        }

        return q_array[q_back];
    }

    void Enqueue(T newData) {
        if (Full()) {
            std::cout << "Queue is full." << std::endl;
            return;
        }

        q_back = (q_back + 1) % q_capacity;
        q_array[q_back] = newData;
        q_size++;
    }

    void Dequeue() {
        if (Empty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        q_front = (q_front + 1) % q_capacity;
        q_size--;
    }

    void Clear() {
        q_front = 0;
        q_back = -1;
        q_size = 0;
    }

    // Copy constructor
    queueArr(const queueArr& other) {
        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;

        q_array = new T[q_capacity];

        for (size_t i = 0; i < q_size; i++) {
            size_t index = (q_front + i) % q_capacity;
            q_array[index] = other.q_array[index];
        }
    }

    // Copy assignment operator
    queueArr& operator=(const queueArr& other) {
        if (this != &other) {

            delete[] q_array;

            q_capacity = other.q_capacity;
            q_size = other.q_size;
            q_front = other.q_front;
            q_back = other.q_back;

            q_array = new T[q_capacity];

            for (size_t i = 0; i < q_size; i++) {
                size_t index = (q_front + i) % q_capacity;
                q_array[index] = other.q_array[index];
            }
        }

        return *this;
    }
};



class Printer {
private:
    queueArr<Job> jobs;

public:
    Printer(int capacity) : jobs(capacity) {
    }

    void AddJob(Job newJob) {

        if (jobs.Full()) {
            std::cout << "Printer queue is full!" << std::endl;
            return;
        }

        jobs.Enqueue(newJob);

        std::cout << "\nJob added successfully!" << std::endl;
        newJob.displayJob();
    }

    void ProcessJobs() {

        if (jobs.Empty()) {
            std::cout << "\nNo print jobs available." << std::endl;
            return;
        }

        std::cout << "\n===== PROCESSING PRINT JOBS =====" << std::endl;

        while (!jobs.Empty()) {

            Job currentJob = jobs.Front();

            std::cout << "\nPrinting job..." << std::endl;
            currentJob.displayJob();

            std::cout << "Job completed!" << std::endl;

            jobs.Dequeue();
        }

        std::cout << "\nAll print jobs have been completed." << std::endl;
    }
};

#endif