#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct playlist {
    char song_name[100];  
    struct playlist* next;  
    struct playlist* prev;  
} playlist;




void insert_song(playlist** head, playlist** tail, char song_name[]);
void delete_song(playlist** head, playlist** tail, char song_name[]);
void display_playlist(playlist* head);
void play_next(playlist** head);
void play_prev(playlist** head);
void play_in_loop(playlist* head);
void play_reverse(playlist* tail);
void play_random(playlist* head);
void shuffle_playlist(playlist** head, playlist** tail);
int count_songs(playlist* head);
int search_song(playlist* head, char song_name[]);
void clear_playlist(playlist** head, playlist** tail);



int main() {
    int choice;
    char song_name[100];
playlist* head=NULL;       
playlist* tail=NULL;                          
while (1) {
        printf("\nMusic Playlist Organizer \n");
        printf("1. Insert Song\n");
        printf("2. Delete Song\n");
        printf("3. Display Playlist\n");
        printf("4. Play Next Song\n");
        printf("5. Play Previous Song\n");
        printf("6. Play in Loop\n");
        printf("7. Play in Reverse\n");
        printf("8. Play Random Song\n");
        printf("9. Count Songs\n");
        printf("10. Search for a Song\n");
        printf("11. Shuffle Playlist\n");
        printf("12. Clear Playlist\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter song name: ");
                scanf(" %[^\n]", song_name); 
                insert_song(&head, &tail, song_name);
                break;

            case 2:
                printf("Enter song name to delete: ");
                scanf(" %[^\n]", song_name); 
               delete_song(&head, &tail, song_name);
                break;
            case 3:
                display_playlist(head);
                break;
            case 4:
                play_next(&head);
                break;
            case 5:
                play_prev(&head);
                break;
            case 6:
                play_in_loop(head);
                break;
            case 7:
                play_reverse(tail);
                break;
            case 8:
                play_random(head);
                break;
            case 9:
                printf("Total songs in playlist: %d\n", count_songs(head));
                break;
            case 10:
                printf("Enter song name to search: ");
                scanf(" %[^\n]", song_name); 
                if (search_song(head,song_name))
                    printf("Song found in playlist!\n");
                else
                    printf("Song not found!\n");
                break;
            case 11:
                shuffle_playlist(&head,&tail);
                break;
            case 12:
                clear_playlist(&head,&tail);
                printf("Playlist cleared!\n");
                break;
            case 13:
                printf("Exiting Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void insert_song(playlist** head, playlist** tail, char song_name[]) {
    playlist* new_song = (playlist*)malloc(sizeof(playlist));

    strcpy(new_song->song_name, song_name); 
    new_song->next = new_song->prev = NULL;

    if (*head == NULL) 
    {
        *head = *tail = new_song;
        new_song->next = new_song->prev = new_song; 
    } 
    else
     {
        new_song->prev = *tail;
        new_song->next = *head;
        (*tail)->next = new_song;
        (*head)->prev = new_song;
        *tail = new_song; 
    }

    printf("Song '%s' added to the playlist!\n", song_name);
}


void delete_song(playlist** head, playlist** tail, char song_name[]) {
    if (*head == NULL) { 
        printf("Playlist is empty! Cannot delete.\n");
        return;
    }

    playlist* current = *head;
    playlist* previous = NULL;

    do {
        if (strcmp(current->song_name, song_name) == 0) {
          
            if (*head == *tail) {
                free(current);
                *head = *tail = NULL;
            }
           
            else if (current == *head) {
                *head = (*head)->next;
                (*head)->prev = *tail;
                (*tail)->next = *head;
                free(current);
            }

            else if (current == *tail) {
                *tail = (*tail)->prev;
                (*tail)->next = *head;
                (*head)->prev = *tail;
                free(current);
            }
            
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                free(current);
            }

            printf("Song '%s' deleted from the playlist!\n", song_name);
            return;
        }

        previous = current;
        current = current->next;
    } while (current != *head); 

    printf("Song '%s' not found in the playlist!\n", song_name);
    return;
}


void display_playlist(playlist* head) {
    if (head == NULL) {
        printf("Playlist is empty!\n");
        return;
    }

    playlist* current = head;
    printf("\nPlaylist Songs\n");

    do {
        printf(" %s\n", current->song_name);
        current = current->next;
    } while (current != head); 

    printf("\n");
}


void play_next(playlist** head) {
    if (*head == NULL) {
        printf("Playlist is empty! No next song to play.\n");
        return;
    }

    *head = (*head)->next; 
    printf(" Now Playing: %s\n", (*head)->song_name);
}



void play_prev(playlist** head) {
    if (*head == NULL) {
        printf("Playlist is empty! No previous song to play.\n");
        return;
    }

    *head = (*head)->prev; 
    printf(" Now Playing: %s\n", (*head)->song_name);
}



void play_in_loop(playlist* head) {
    if (head == NULL) {
        printf("Playlist is empty! Nothing to play.\n");
        return;
    }

    playlist* current = head;

    printf("\n Playing Playlist in Loop 🎶\n");
    do {
        printf("Now Playing: %s\n", current->song_name);
        current = current->next;
    } while (current != head); 

}

  
void play_reverse(playlist* tail) {
    if (tail == NULL) {
        printf("Playlist is empty! Nothing to play in reverse.\n");
        return;
    }

    playlist* current = tail;

    printf("\nPlaying Playlist in Reverse \n");
    do {
        printf(" Now Playing: %s\n", current->song_name);
        current = current->prev;
    } while (current != tail->prev); 
}    
   

void play_random(playlist* head) {
    if (!head) {
        printf("Playlist is empty! Cannot play a random song.\n");
        return;
    }

    srand(time(NULL));  
    playlist* current = head;
    int random_steps = rand() % count_songs(head);  

    while (random_steps--)  
        current = current->next;  

    printf("Playing Random Song: %s\n", current->song_name);
}

int count_songs(playlist* head) {
    if (head == NULL) {
        return 0; 
    }

    int count = 0;
    playlist* temp = head;

    do {
        count++;  
        temp = temp->next;  
    } while (temp != head);  

    return count;
}

int search_song(playlist* head, char song_name[]) {
    if (head == NULL) {
        return 0;  
    }

    playlist* temp = head;
    
    do {
        if (strcmp(temp->song_name, song_name) == 0) {
            return 1;  
        }
        temp = temp->next;
    } while (temp != head);  

    return 0; 
}

void shuffle_playlist(playlist** head, playlist** tail) {
    if (*head == NULL || (*head)->next == *head) {
        printf("Playlist is empty or has only one song. Nothing to shuffle!\n");
        return;
    }

    int count = count_songs(*head); 
    playlist* current = *head;
    playlist* randomNode;
    srand(time(NULL));  

    for (int i = 0; i < count; i++) {
        int randIndex = rand() % count;  
        randomNode = *head;
        
       
        for (int j = 0; j < randIndex; j++) {
            randomNode = randomNode->next;
        }

        
        char temp[100];
        strcpy(temp, current->song_name);
        strcpy(current->song_name, randomNode->song_name);
        strcpy(randomNode->song_name, temp);

        current = current->next;  
    }

    printf("Playlist shuffled!\n");
}

void clear_playlist(playlist** head, playlist** tail) 
{
    if (*head == NULL) {
        printf("Playlist is already empty!\n");
        return;
    }

    playlist* current = *head;
    playlist* temp;

    (*tail)->next = NULL;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    *head = NULL;
    *tail = NULL;

    printf("Playlist cleared!\n");
}



