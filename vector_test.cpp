#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int total_students;
	int total_courses;
	scanf("%d%d",&total_students,&total_courses);
	std::vector<vector<string> > course(total_courses);
	for(int i=0;i<total_students;i++)
	{
		int selected_course;
		string temp_stu_name;
		cin>>temp_stu_name>>selected_course;
		for(int j=0;j<selected_course;j++)
		{
			int kth;
			cin>>kth;
			course[kth-1].push_back(temp_stu_name);
		}
	}
	for(int i=0;i<total_courses;i++)
	{
		sort(course[i].begin(),course[i].end());
		cout<<i+1<<" "<<course[i].size()<<endl;
		for(int j=0;j<course[i].size();j++)
		{
			cout<<course[i][j]<<endl;
		}
	}
	return 0;


}