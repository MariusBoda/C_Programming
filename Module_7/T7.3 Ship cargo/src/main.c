#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * \brief Ship data structure
 *
 * \details A ship is composed of three fields:
 *          - name: the human readable name of the ship
 *          - weight: the weight of the ship in tonnes. The weight does not need to be an integer.
 *          - cargo: an array of strings that contains human
 *                   readable names of the cargo. The number
 *                   different cargo can be assumed known in advance
 *                   (e.g. 10). The cargo names will not change during the
 *                   program execution.
 */
struct Ship
{
    char name[50];     // Maximum length of the ship name is assumed to be 50 characters
    float weight;
    char cargo[10][50]; // Array of strings to store cargo names
};

/**
 * \brief Clears the cargo of the ship vessel by setting its cargo names to an empty string.
 *
 * \param vessel The vessel of which cargo will be cleared.
 */
void clear_cargo(struct Ship *vessel)
{
    for (int i = 0; i < 10; i++)
    {
        strcpy(vessel->cargo[i], "");
    }
}

/**
 * \brief Adds the specified cargo to the ship vessel.
 *
 * \param vessel The ship that the cargo will be assigned
 * \param cargo The name of the cargo to be assigned
 */
void add_cargo(struct Ship *vessel, const char *cargo)
{
    int length = strlen(cargo);
    if (length >= 50)
    {
        printf("cargo name is too long");
        return;
    }
    int empty_slot = -1;
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(vessel->cargo[i], "") == 0)
        {
            empty_slot = i;
            break;
        }
    }

    if (empty_slot == -1)
    {
        printf("too full");
        return;
    }
    strcpy(vessel->cargo[empty_slot], cargo);
}

int main(void)
{
    struct Ship vessel_1 = {"Tanker", 100000, {""}};

    clear_cargo(&vessel_1);
    add_cargo(&vessel_1, "Gasoline");
    add_cargo(&vessel_1, "Oil");
    add_cargo(&vessel_1, "Diesel");

    struct Ship vessel_2;
    strcpy(vessel_2.name, "Fun boat");
    vessel_2.weight = 1.25;
    clear_cargo(&vessel_2);
    add_cargo(&vessel_2, "Food basket");
    add_cargo(&vessel_2, "Sunscreen");
    add_cargo(&vessel_2, "Very good lemonade");
    add_cargo(&vessel_2, "Frankfurters");

    struct Ship ships[2];
    ships[0] = vessel_1;
    ships[1] = vessel_2;

    for (int i = 0; i < 2; i++)
    {
        printf("Name: %s  / Weight %.2f tonnes\n", ships[i].name, ships[i].weight);
        printf("Cargo:\n");
        for (int j = 0; j < 10; j++)
        {
            if (strcmp(ships[i].cargo[j], "") != 0)
            {
                printf("* %s\n", ships[i].cargo[j]);
            }
        }
        printf("----------\n");
    }

    return 0;
}
