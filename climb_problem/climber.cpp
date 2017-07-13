#include <stdio.h>
#include <assert.h>

#define H_ARRAYSIZE(a) \
    ((sizeof(a) / sizeof(*(a))) / \
    static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

int resolve(const char* input)
{
	int step, height = 0, index1, index2 = 6, index3 = 8, i = 0, hor;

	index1 = 2 + (input[0] - '0' - 1) * 6 + 2;
	hor = input[index1] - '0';
	while (i < (input[0] - 48))
	{
		height += (input[index2] - '0') * 2;
		index2 += 6;
		i++;
	}
	for (int j = 0; j < input[0] - 49; j++)
	{
		if (input[index3] <= input[index3 - 4])
		{
			if (input[index3 + 4] > input[index3 - 2])
				height -= (input[index3 - 2] - '0') * 2;
			else
				height -= (input[index3 + 4] - 48) * 2;
		}
		index3 += 6;
	}
	step = hor + height;
	return step;

}

int main(int argc, char* argv[])
{
	const char* input[] = {
		"3\n1,3,2\n2,4,4\n6,7,5\n", //The giving example
		"1\n1,2,1\n",
		"2\n1,2,1\n2,3,2",
		"3\n1,2,1\n2,3,2\n3,6,1",
		"4\n1,2,1\n2,3,2\n3,6,1\n5,8,2",
		"5\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n7,9,1",
		"1\n0,1,1",
		"2\n0,1,1\n2,4,3",
		"3\n0,1,1\n2,4,3\n3,5,1",
		"4\n0,1,1\n2,4,3\n3,5,1\n5,6,1",
		"5\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3",
		//TODO please add more test case here
	};
	int expectedSteps[] = { 25, 4, 7, 10, 14, 15, 3, 12, 13, 14, 20 };
	for (size_t i = 0; i < H_ARRAYSIZE(input); ++i)
	{
		assert(resolve(input[i]) == expectedSteps[i]);
	}
	return 0;
}