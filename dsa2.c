#include <stdio.h>
#include <string.h>

int main() 
{ 
    char STR[100], PAT[100], REP[100], ans[200]; // Increased size for ans
    int i, j, c, m, k, flag = 0; 
    printf("\nEnter the MAIN string: \n"); 
    fgets(STR, sizeof(STR), stdin); 
    STR[strcspn(STR, "\n")] = '\0'; // Remove newline character

    printf("\nEnter a PATTERN string: \n"); 
    fgets(PAT, sizeof(PAT), stdin); 
    PAT[strcspn(PAT, "\n")] = '\0'; // Remove newline character

    printf("\nEnter a REPLACE string: \n"); 
    fgets(REP, sizeof(REP), stdin); 
    REP[strcspn(REP, "\n")] = '\0'; // Remove newline character

    i = 0; 
    j = 0; 
    c = 0; 

    while (STR[c] != '\0') 
    { 
        // Check for pattern match
        if (STR[c] == PAT[i]) 
        { 
            i++; 
            if (PAT[i] == '\0') // If we reach the end of PAT
            { 
                // Replace the pattern with the replacement string
                for (k = 0; REP[k] != '\0'; k++, j++) 
                    ans[j] = REP[k]; 
                i = 0; // Reset i to start searching again
                c++; // Move to the next character in STR
            } 
            else 
            {
                c++; // Move to the next character in STR
            }
        } 
        else // Mismatch
        { 
            if (i > 0) // If there was a partial match
            {
                // Write the matched characters to ans
                for (int x = 0; x < i; x++)
                    ans[j++] = PAT[x]; 
            }
            // Copy the current character from STR
            ans[j++] = STR[c]; 
            c++; 
            i = 0; // Reset i
        } 
    }

    // Add remaining characters if there's any unmatched pattern
    while (i > 0) {
        for (int x = 0; x < i; x++)
            ans[j++] = PAT[x]; 
        i = 0;
    }

    // Null terminate the resultant string
    ans[j] = '\0';

    if (j == 0 || (strstr(STR, PAT) == NULL)) 
    { 
        printf("Pattern doesn't found!!!\n"); 
    } 
    else 
    { 
        printf("\nThe RESULTANT string is: %s\n", ans); 
    } 
}
