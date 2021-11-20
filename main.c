#include <stdio.h>
#include <stdlib.h>


void get_input(char *message, double *value_to_store)
{
    _Bool input_valid = 0;
    while(!input_valid)
    {
        printf("Please enter %s: ", message);
        if(!scanf("%lf", value_to_store))
        {
            puts("Invalid value, please enter a number");
            int c;
            // clear input buffer if input is bad
            // (remove everything up to the new line, when user pressed enter)
            while((c = getchar()) != EOF && c != '\n') {}
        } else
        {
            printf("You entered: %.2lf\n", *value_to_store);
            input_valid = 1;
        }
    }
}


int main(void)
{
    double floor_length, floor_width, floor_area;
    double room_height, room_volume;
    double wall_one_length, wall_two_length, wall_three_length, wall_four_length;
    double paint_needed;

    get_input("floor length", &floor_length);
    get_input("floor width", &floor_width);
    floor_area = floor_length * floor_width;
    get_input("room height", &room_height);
    room_volume = floor_area * room_height;
    get_input("wall one length", &wall_one_length);
    get_input("wall two length", &wall_two_length);
    get_input("wall three length", &wall_three_length);
    get_input("wall four length", &wall_four_length);

    // Total surface area calculated by adding surface area of all walls.
    // This can be done seperately, however I have shortened it using a distributivity law
    paint_needed = (wall_one_length + wall_two_length + wall_three_length + wall_four_length) * room_height;
    printf("The area of the floor is %.2lf\n", floor_area);
    printf("The amount of paint needed to paint the walls is: %.2lf\n", paint_needed);
    printf("The volume of the room is: %.2lf\n", room_volume);
    scanf("%c");

    return 0;
}