#ifndef SIMDEF_H
# define SIMDEF_H

# define TERMINATE_TIME 20

typedef enum SimStatusType
{
    arrival,
    start,
    end
} SimStatus;

typedef struct SimCustomerType
{
    SimStatus status;
    int is_VIP;
    int arrivalTime;
    int serviceTime;
    int startTime;
    int endTime;
} SimCustomer;

#endif

