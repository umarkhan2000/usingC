// CSC A48 - Exercise 9 - DNA alignment Pt. 1
//
// The goal of this assignment is to write a function that
// translates tripled (sets of 3) DNA nucleotide bases to
// the corresponding aminoacid.
//
// As a brief review of your Biology lessons, DNA is a double
// stranded chain of nucleic-acids, there are 4 types of
// nucleotides denoted by the letters:
//
// A, C, T, G
//
// The sequence of these nucleotides specifies the sequence
// in which aminoacids (the building blocks of proteins)
// are assembled into every single one of the proteins that
// make up the cells of most licing things (there are a 
// few that do not use DNA, opting instead to use the single
// stranded version called RNA, viruses tend to be sneaky
// that way!)
//
// Each set of 3 nucleotides specifies one aminoacid in
// a protein's specification.
//
// The goal of this exercise is for you to write a small
// function that takes in a DNA sequence (a string made up
// of letters ATCG in some sequence) and determines the
// corresponding sequence of aminoacids. Below, you will
// find a table listing each aminoacid, and the sequences
// of DNA nucleotides that specify that aminoacid.
// 
// Note that many aminoacids can be specified by more than
// one triplet!
//
//  Aminoacid   Single letter name	Triplets
//  Isoleucine 		I 		ATT, ATC, ATA
//  Leucine 		L 		CTT, CTC, CTA, CTG, TTA, TTG
//  Valine 		V 		GTT, GTC, GTA, GTG
//  Phenylalanine 	F 		TTT, TTC
//  Methionine 		M 		ATG
//  Cysteine 		C 		TGT, TGC
//  Alanine 		A 		GCT, GCC, GCA, GCG
//  Glycine 		G 		GGT, GGC, GGA, GGG
//  Proline 		P 		CCT, CCC, CCA, CCG
//  Threonine 		T		ACT, ACC, ACA, ACG
//  Serine 		S 		TCT, TCC, TCA, TCG, AGT, AGC
//  Tyrosine 		Y 		TAT, TAC
//  Tryptophan 		W 		TGG
//  Glutamine 		Q 		CAA, CAG
//  Asparagine 		N 		AAT, AAC
//  Histidine 		H 		CAT, CAC
//  Glutamic acid 	E 		GAA, GAG
//  Aspartic acid 	D 		GAT, GAC
//  Lysine 		K 		AAA, AAG
//  Arginine 		R 		CGT, CGC, CGA, CGG, AGA, AGG
//
//  Your task is to determine whether two DNA sequences use the
//  same number of each type of aminoacid (the order of the
//  amino-acids doesn't matter here).
//  To that end, you need to write a function that
//  takes a DNA sequence and converts it to the corresponding
//  sequence of aminoacids, for instance if the input sequence is:
//
//  AAGGAGTGTTTT
//
//  Your function must return
//
//  KECF
//
//  Then you need to write a function that takes in two DNA
//  sequences and determines whether they produce the same
//  numbers of each aminoacid. For example, if the sequence
//  of aminoacids for each of the input DNA sequences is
//
//  AATVKFAA    and    TAAVKAAF
//
//  The function must return 1 (they produce the same number
//  of each aminoacid). However, if the aminoacid sequences
//  are
//
//  TVFAAKVV    and    ECVAATFK
//
//  the function will return 0 (not the same number of each
//  aminoacid).
//
// (c) F. Estrada, March, 2019

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void DNA_sequencing(char inputDNA[1024], char outputAminoAcids[1024])
{
    // This function receives two strings, one that contains a sequence
    // of DNA nucleotides (which MUST be composed of the letters
    // ACGT, no spaces or other symbols can appear here!), and
    // updates an initially empty string 'outputAminoAcids' with the
    // sequence of aminoacids corresponding to the input DNA sequence
    //
    // Try to make this function as compact (fewer lines of code, more
    // elegant, easier to read code) as possible. APply what you've
    // learned in Exercises 6-8, all of which helped you practice
    // using strings!

    // To Do:
    // Complete this function
	
	outputAminoAcids[0] = '\0';
	int i = 0;
	char nucleotide[100][3] = {"ATT", "ATC", "ATA", "CTT", "CTC", "CTA", "CTG", "TTA", "TTG", "GTT", "GTC", "GTA", "GTG", "TTT", "TTC",	"ATG",
							"TGT","TGC", "GCT", "GCC", "GCA", "GCG", "GGT", "GGC", "GGA", "GGG", "CCT", "CCC", "CCA", "CCG", "ACT", "ACC", "ACA",
							"ACG", "TCT", "TCC", "TCA", "TCG", "AGT", "AGC", "TAT", "TAC", "TGG", "CAA", "CAG", "AAT", "AAC", "CAT", "CAC", "GAA",
							"GAG", "GAT", "GAC", "AAA", "AAG", "CGT", "CGC", "CGA", "CGG", "AGA", "AGG", "END"};

	char one_letter[100] = {'I', 'I', 'I', 'L', 'L', 'L', 'L', 'L', 'L', 'V', 'V', 'V', 'V', 'F', 'F', 'M', 'C', 'C', 'A', 'A', 'A', 'A', 'G', 'G',
							'G', 'G', 'P', 'P', 'P', 'P', 'T', 'T', 'T', 'T', 'S', 'S', 'S', 'S', 'S', 'S',	'Y', 'Y', 'W', 'Q', 'Q', 'N', 'N', 'H',
							'H', 'E', 'E', 'D', 'D', 'K', 'K', 'R', 'R', 'R', 'R', 'R', 'R'};
							
	while (inputDNA[i+2] != '\0')
	{
		char DNA_list[4];
		DNA_list[0] = inputDNA[i];
		DNA_list[1] = inputDNA[i+1];
		DNA_list[2] = inputDNA[i+2];
		DNA_list[3] = '\0';
		int j = 0;
		
		while(strcmp(nucleotide[j] ,"END") != 0)
		{
			if(nucleotide[j][0] == DNA_list[0] && nucleotide[j][1] == DNA_list[1] && nucleotide[j][2] == DNA_list[2])
			{
				char add[2];
				add[0] = one_letter[j];
				add[1] = '\0';
				strcat(outputAminoAcids, add);
			}
			j++;
		}
		i = i + 3;
	}
}

int amino_matching(char inputDNA1[1024], char inputDNA2[1024])
{
    // This function receives two strings representing DNA
    // sequences. It returns 1 if the sequences produce the
    // same number of each type of aminoacid. Think carefully
    // about the best (simplest?) way to to this.

    // To Do:
    // Complete this function
	
	int length_DNA1 = strlen(inputDNA1);
    int length_DNA2 = strlen(inputDNA2);
	
	if (length_DNA1 != length_DNA2)
	{
		return 0;
	}
	char copy;
	
	for (int i = 0; i < length_DNA1-1; i++)
	{
    	for (int j = i+1; j < length_DNA1; j++)
		{
        	if (inputDNA1[i] > inputDNA1[j]) 
			{
            	copy  = inputDNA1[i];
            	inputDNA1[i] = inputDNA1[j];
            	inputDNA1[j] = copy;
         	}
         	if (inputDNA2[i] > inputDNA2[j])
			{
            	copy  = inputDNA2[i];
            	inputDNA2[i] = inputDNA2[j];
            	inputDNA2[j] = copy;
        	}
    	}
	}

	for(int i = 0; i<length_DNA1; i++) 
	{
    	if(inputDNA1[i] != inputDNA2[i])
		{
        	return 0;
    	}
	}

	return 1;
}

#ifndef __testing

int main()
{
	char DNAseq1[1024]="CTTATTGTTCCAATGTGGCGGCACTACACGTGCGTTATC";
	char DNAseq2[1024]="ATTTATTGTACATATCATCGTTGGATGCCCGTAATATTG";
        char DNAseq3[1024]="ATCGTTTGCACGTACCACCGGTGGATGCCAGTTATTCTT";
	char aminoAcids[1024]="";

	printf("Input DNA sequence 1: %s\n",DNAseq1);
	DNA_sequencing(DNAseq1,aminoAcids);
	printf("Output aminoacid sequence 1: %s\n",aminoAcids);

	printf("Input DNA sequence 2: %s\n",DNAseq2);
	DNA_sequencing(DNAseq2,aminoAcids);
	printf("Output aminoacid sequence 2: %s\n",aminoAcids);

	printf("Input DNA sequence 3: %s\n",DNAseq3);
	DNA_sequencing(DNAseq3,aminoAcids);
	printf("Output aminoacid sequence 3: %s\n",aminoAcids);

	if (amino_matching(DNAseq1,DNAseq2)==1)
	{
		printf("Sequence 1 matches sequence 2 in aminoacids\n");
	}
	else
	{
		printf("Sequence 1 does not match sequence 2 in aminoacids\n");
	}

	if (amino_matching(DNAseq1,DNAseq3)==1)
	{
		printf("Sequence 1 matches sequence 3 in aminoacids\n");
	}
	else
	{
		printf("Sequence 1 does not match sequence 3 in aminoacids\n");
	}

	if (amino_matching(DNAseq2,DNAseq3)==1)
	{
		printf("Sequence 2 matches sequence 3 in aminoacids\n");
	}
	else
	{
		printf("Sequence 2 does not match sequence 3 in aminoacids\n");
	}

	return 0;
}

#endif
