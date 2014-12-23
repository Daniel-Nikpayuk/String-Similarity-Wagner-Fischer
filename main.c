/*************************************************************************************************************************
**
** Copyright 2014 Daniel Nikpayuk
**
** This file is part of Wagner_Fischer.
**
** Wagner_Fischer is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
**
** Wagner_Fischer is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
** of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with Wagner_Fischer. If not, see
** <http://www.gnu.org/licenses/>.
**
*************************************************************************************************************************/

#include<stdio.h>
#include<string.h>

long unsigned min(long unsigned x, long unsigned y, long unsigned z)
{
	return (x < y ? (x < z ? x : z) : (y < z ? y : z));
}

long unsigned wagner_fischer(const char str1[], const char str2[])
{
	long unsigned len=strlen(str2)+1;
	long unsigned above[len], below[len];
	for (long unsigned *k=above, c=0; k < above+len; ++k, ++c) *k=c;

	const char *str1_at=str1, *str2_at;
	for (long unsigned j=1; j < strlen(str1)+1; ++j)
	{
		*below=j;
		str2_at=str2;
		for (long unsigned *d=above, *a=above+1, *l=below, *c=below+1; c < below+len; ++d, ++a, ++l, ++c)
		{
			*c=min(*str1_at == *str2_at ? *d : *d+1, *a+1, *l+1);
			++str2_at;
		}
		for (long unsigned *a=above, *b=below; a < above+len; ++a, ++b) *a=*b;
		++str1_at;
	}

	return above[len-1];
}

int main(int argc, char *argv[])
{
	if (argc == 3) printf("%lu\n", wagner_fischer(argv[1], argv[2]));

	return 0;
}

