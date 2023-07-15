int lower_than_key(double grade,treetype root)
{
	if(root!=NULL)
    {
	if(root->key.grade<grade)
	{printf("%-30s%.2lf\n",root->key.name,root->key.grade);
	return 1+lower_than_key(grade,root->left)+lower_than_key(grade,root->right);
	}
	else
	return lower_than_key(grade,root->left)+lower_than_key(grade,root->right) ;
	}
	else return 0;
}
int higher_than_key(double grade,treetype root)
{
	if(root!=NULL)
    {
	if(root->key.grade>grade)
	{printf("%-30s%.2lf\n",root->key.name,root->key.grade);
	return 1+higher_than_key(grade,root->left)+higher_than_key(grade,root->right);
	}
	else
	return higher_than_key(grade,root->left)+higher_than_key(grade,root->right) ;
	}
	else return 0;
}