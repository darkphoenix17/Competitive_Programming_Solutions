int setBitNumber(int n)
{
	int k = (int)(log2(n));
	return 1 << k;
}