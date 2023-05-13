#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char filename[50], ch;
    int choice, position, count = 0;

    while (1)
    {
        printf("\nFile Management Operations\n");
        printf("1. Create a new file\n");
        printf("2. Modify an existing file\n");
        printf("3. Delete a file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the filename to create: ");
            scanf("%s", filename);
            fp = fopen(filename, "w");
            if (fp == NULL)
            {
                printf("Error creating file!\n");
                exit(1);
            }
            printf("File created successfully.\n");
            fclose(fp);
            break;

        case 2:
            printf("\nEnter the filename to modify: ");
            scanf("%s", filename);
            fp = fopen(filename, "r+");
            if (fp == NULL)
            {
                printf("Error opening file!\n");
                exit(1);
            }
            fseek(fp, 0, SEEK_END);
            count = ftell(fp);
            printf("The file '%s' contains %d characters.\n", filename, count);
            printf("Enter the position to modify (0-%d): ", count - 1);
            scanf("%d", &position);
            fseek(fp, position, SEEK_SET);
            printf("Enter the new character: ");
            scanf(" %c", &ch);
            fputc(ch, fp);
            fclose(fp);
            printf("File modified successfully.\n");
            break;

        case 3:
            printf("\nEnter the filename to delete: ");
            scanf("%s", filename);
            if (remove(filename) == 0)
            {
                printf("File deleted successfully.\n");
            }
            else
            {
                printf("Error deleting file!\n");
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice!\n");
            break;
        }
    }

    return 0;
}
