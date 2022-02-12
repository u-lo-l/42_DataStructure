#ifndef SIMDEF_H
# define SIMDEF_H

typedef enum SimStatusType
{
    arrival,
    start,
    end
} SimStatus;

typedef struct SimCustomerType
{
    SimStatus status;
    int arrivalTime;
    int serviceTime;
    int startTime;
    int endTime;
} SimCustomer;

#endif

