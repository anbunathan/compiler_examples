while (!feof(f2))
		{
			if (strcmp(m1, otp) == 0)
			{
				lc = lc + 3;
				break;
			}
			fscanf(f2, "%s %d", otp, &o);
		}
		fclose(f2);
		if (strcmp(m1, "WORD") == 0)
		{
			lc = lc + 3;
		}
		else if (strcmp(m1, "RESW") == 0)
		{
			op1 = atoi(op); 
			lc = lc + (3 * op1);
		}
		else if (strcmp(m1, "BYTE") == 0)
		{
			if (op[0] == 'X')
				lc = lc + 1;
			else
			{
				len = strlen(op) - 2;
				lc = lc + len;
			}
		}
		else if (strcmp(m1, "RESB") == 0)
		{
			op1 = atoi(op);
			lc = lc + op1;
		}