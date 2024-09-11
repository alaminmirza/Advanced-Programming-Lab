#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void Title_Screen()
{
	printf("\t ________    __   __ _______ __    _ _______ __   __ _______ __    _ \n"
		   "\t|/   |      |  | |  |   _   |  |  | |       |  |_|  |   _   |  |  | |\n"
		   "\t|    |      |  |_|  |  |_|  |   |_| |    ___|       |  |_|  |   |_| |\n"
		   "\t|   (_)     |       |       |       |   | __|       |       |       |\n"
		   "\t|   /|\\     |       |       |  _    |   ||  |       |       |  _    |\n"
		   "\t|    |      |   _   |   _   | | |   |   |_| | ||_|| |   _   | | |   |\n"
		   "\t|   | |     |__| |__|__| |__|_|  |__|_______|_|   |_|__| |__|_|  |__|\n"
		   "\t|________\n"
		   "\t[________]               Be Aware, You can be Hanged !\n\n\n"
		   "--------------------------------------------------------------------------------------\n"
		   "==============================>>> Hit Enter to Start <<<==============================\n"
		   "--------------------------------------------------------------------------------------\n\n\t\t\t\t\t");
}


void Rules_Screen()
{
	printf("\t ____        _\n"
		   "\t|  _ \\ _   _| | ___  ___\n"
		   "\t| |_) | | | | |/ _ \\/ __|\n"
		   "\t|  _ <| |_| | |  __/\\__ \\\n"
		   "\t|_| \\_\\\\____|_|\\___||___/\n\n"
		   "\t  - Maximum 6 wrong are Allowed.\n"
		   "\t  - All words are Name of 13 Districts in Dhaka of Bangladesh. eg. 'Dhaka'\n"
		   "\t  - If you Enjoy Continue, otherwise Close it.\n\n"
		   "\t     Syntax : Alphabet Only (Lower or Upper Case)\n"
		   "\t     Example : 'A' or 'a'\n\n\n"
		   "--------------------------------------------------------------------------------------\n"
		   "=============================>>> Hit Enter to Continue <<<============================\n"
		   "--------------------------------------------------------------------------------------\n\n\t\t\t\t\t");
}


void Gameover_Screen(char *word)
{
	printf("         ________\n"
		   "        |/   |           ______                        ____\n"
		   "        |    |          / ____/___ _____ ___  ___     / __ \\_   _____  _____\n"
		   "        |   (_)        / / __/ __ `/ __ `__ \\/ _ \\   / / / / | / / _ \\/ ___/\n"
		   "        |   /|\\       / /_/ / /_/ / / / / / /  __/  / /_/ /| |/ /  __/ /\n"
		   "        |    |        \\____/\\____/_/ /_/ /_/\\___/   \\____/ |___/\\___/_/\n"
		   "        |   | |\n"
		   "        |________\n"
		   "        [________]\n\n\n"
		   "\t\t\tBetter Luck next time. Word was '%s'\n\n\n"
		   "\t\t\t\t>>>> Try Again..? <<<<\n\n\n"
		   "--------------------------------------------------------------------------------------\n"
		   "=============================>>> Hit Enter to Continue <<<============================\n"
		   "--------------------------------------------------------------------------------------\n\n\t\t\t\t\t", word);

		   getchar();
		   free(word);
}


void Win_Screen(char *word)
{
	printf("         ________\n"
		   "        |/               __  __               _       __               __\n"
		   "        |                \\ \\/ /___  __  __   | |     / /___  ____     / /\n"
		   "        |                 \\  / __ \\/ / / /   | | /| / / __ \\/ __ \\   / /\n"
		   "        |   (_)           / / /_/ / /_/ /    | |/ |/ / /_/ / / / /  /_/\n"
		   "        |   \\|/          /_/\\____/\\____/     |__/|__/\\____/_/ /_/  (_)\n"
		   "        |    |\n"
		   "        |___|_|__\n"
		   "        [________]\n\n\n"
		   "\t\t   Congrats! You have Won. The Word was '%s'\n\n\n"
		   "\t\t\t\t  >>>> Play Again..? <<<<\n\n\n"
		   "--------------------------------------------------------------------------------------\n"
		   "=============================>>> Hit Enter to Continue <<<============================\n"
		   "--------------------------------------------------------------------------------------\n\n\t\t\t\t\t", word);
		   
		   getchar();
		   free(word);
}


void Print_Word(char *guess_letter, int word_length) {
	printf("\n        Word: ");
	for (int i = 0; i < word_length; ++i)
	{
		printf("%c ", guess_letter[i]);
	}
}


void Print_Body(int mistakes, char *guess_letter, int word_length)
{
	switch(mistakes)
	{
		case 0: printf("         ________\n"
					   "        |/   |\n"
					   "        |\n"
					   "        |\n"
					   "        |\n"
					   "        |\n"
					   "        |\n"
					   "        |________\n"
					   "        [________]\n\n\n"); 
				Print_Word(guess_letter, word_length);
				printf("        Mistakes: %d", mistakes); break;

		case 1: printf("         ________\n"
					   "        |/   |\n"
					   "        |   (_)\n"
					   "        |\n"
					   "        |\n"
					   "        |\n"
					   "        |\n"
					   "        |________\n"
					   "        [________]\n\n\n");
				Print_Word(guess_letter, word_length);
				printf("        Mistakes: %d", mistakes); break;

		case 2: printf("         ________\n"
					   "        |/   |\n"
					   "        |   (_)\n"
					   "        |    |\n"
					   "        |    |\n"
					   "        |\n"
					   "        |\n"
					   "        |________\n"
					   "        [________]\n\n\n");
				Print_Word(guess_letter, word_length);
				printf("        Mistakes: %d", mistakes); break;

		case 3: printf("         ________\n"
					   "        |/   |\n"
					   "        |   (_)\n"
					   "        |   \\|\n"
					   "        |    |\n"
					   "        |\n"
					   "        |\n"
					   "        |________\n"
					   "        [________]\n\n\n");
				Print_Word(guess_letter, word_length);
				printf("        Mistakes: %d", mistakes); break;

		case 4: printf("         ________\n"
					   "        |/   |\n"
					   "        |   (_)\n"
					   "        |   \\|/\n"
					   "        |    |\n"
					   "        |\n"
					   "        |\n"
					   "        |________\n"
					   "        [________]\n\n\n");
				Print_Word(guess_letter, word_length);
				printf("        Mistakes: %d", mistakes); break;

		case 5: printf("         ________\n"
					   "        |/   |\n"
					   "        |   (_)\n"
					   "        |   \\|/\n"
					   "        |    |\n"
					   "        |   /\n"
					   "        |\n"
					   "        |________\n"
					   "        [________]\n\n\n");
				Print_Word(guess_letter, word_length);
				printf("        Mistakes: %d", mistakes); break;

		default: break;
	}
}


bool srand_called = false;

int Random_Number(int i)
{
    if (!srand_called) {
        srand(time(NULL) << 10);
        srand_called = true;
    }
    return rand() % i;
}


char *Decrypt(char *code) {
	int hash = ((strlen(code) - 3) / 3) + 2;
	char* decrypt = malloc(hash);
	char* toFree = decrypt;
	char* word = code;
	for (int ch = *code; ch != '\0'; ch = *(++code))
	{
		if((code - word + 2) % 3  == 1){
			*(decrypt++) = ch - (word - code + 1) - hash;
		}
	}
	*decrypt = '\0';
	return toFree;
}


char encrypted_district_list[13][37] = {"P^I[uJYK@CcG|W:H}", "=cN[ZFndTZDHoQ@uXIw~KHeETD", "reNlnE\\y[JsGfIKNSMVSGuJ", "|TPvgURYSW=AmgIPQA``8GBBnQ;iS",
					"fbV{RQT{XzHJQZNlkN[O>Ik=KO4dZ>HH7_T", "hiV[fG?HGnrAliOvBCFEGa@IyCC||", "mxVEXGLrQo\\IFxHn@A>T8bRBPQ;KT", "@kW~T\\DpRSmTJKFKoDlg?l>6vN@BP9SB",
					"I^YgaIbkWT=CWPX{h=kPGAM=bk4in>du7gM", "f~WKVGiaUmjSLbF}jHZI>r|8mK:Fb", "P_YekEHEKMG@~U<\\rJAX>O]", "zO]__OQjE[OSAfG{b<ppLZ^ES?GaCAGp",
					"x][GtETcOYDE?Z<i^AgjA>^"};

int main(void)
{
	char *decrypted_word, *encrypted_word, *guessed_part, *win, false_guess[6], guess_letter, user_input[100];
	int decrypted_word_length, mistakes = 0, correct = 0;
	bool already_guessed;

	encrypted_word = encrypted_district_list[Random_Number(13)];
	decrypted_word = Decrypt(encrypted_word);

	decrypted_word_length = strlen(decrypted_word);
	guessed_part = malloc(decrypted_word_length);
	memset(guessed_part, '_', decrypted_word_length);

	system("cls");
	Title_Screen();
	getchar();

	system("cls");
	Rules_Screen();
	getchar();

	while(mistakes < 6 && win != NULL)
	{
		system("cls");
		Print_Body(mistakes, guessed_part, decrypted_word_length);
		printf("        Wrong Guesses : ");

		if(mistakes == 0)
		{
			printf(" None");
		}

		for (int i = 0; i < mistakes; ++i)
		{
			printf(" '%c'", false_guess[i]);
		}

		printf("\n\n\n\n        Enter a letter to guess : ");
		fgets(user_input, sizeof(user_input), stdin);
		guess_letter = user_input[0];
		guess_letter = toupper(guess_letter);

		already_guessed = false;

		for (int i = 0; i < decrypted_word_length; i++)
		{
			if(decrypted_word[i] == guess_letter)
			{ 
				guessed_part[i] = guess_letter;
				already_guessed = true;
			}
		}

		if(!already_guessed)
		{
			if (guess_letter != ' '  && guess_letter != '\n' && strchr(false_guess, guess_letter) == NULL)
			{
				false_guess[mistakes] = guess_letter;
				mistakes++;

			}
		}

		win = strchr(guessed_part, '_');
	}

	if(win == NULL)
	{
		system("cls");
		printf("\n");
		Win_Screen(decrypted_word);
	}

	else
	{
		system("cls");
		printf("\n");
		Gameover_Screen(decrypted_word);
	}

	free(win);
	free(guessed_part);
	free(decrypted_word);
	free(encrypted_word);
}