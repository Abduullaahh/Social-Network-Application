#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
int CHK = 0;
class helper
{
public:
	int getlength(const char* string)
	{
		int size = 0;
		for (int i = 0; string[i] != '\0'; i++)
		{
			size++;
		}
		return size;
	}
	int getcounterstr(int start, char end, string str)
	{
		int count = 0;
		for (int i = start; str[i] != end; i++)
		{
			count++;
		}
		return count;
	}
	int getcounterchar(int start, char end, char* str)
	{
		int count = 0;
		for (int i = start; str[i] != end; i++)
		{
			count++;
		}
		return count;
	}
};
class Activity
{
private:
	char* ID;
	char* Value;
public:
	Activity(char* id = 0, char* type = 0)
	{
		int s = 0;
		int i = 0;
		if (*id == '1')
		{
			for (; type[i] != '\0'; i++)
			{
				s++;
			}
			Value = new char[s + 1];
			for (i = 0; type[i] != '\0'; i++)
			{
				Value[i] = type[i];
			}
			Value[i] = '\0';
			s = 0;
			i = 0;
			char feel[8] = { 'f','e',' e','l','i','n','g','\0' };
			ID = new char[8];
			for (i = 0; i < 8; i++)
			{
				ID[i] = feel[i];
			}
		}
		else if (*id == '2')
		{
			for (; type[i] != '\0'; i++)
			{
				s++;
			}
			Value = new char[s];
			for (i = 0; type[i] != '\0'; i++)
			{
				Value[i] = type[i];
			}
			Value[i] = '\0';
			s = 0;
			i = 0;
			char feel[15] = { 't','h','i','n','k','i','n','g',' ','a','b','o','u','t','\0' };
			ID = new char[15];
			for (i = 0; i < 15; i++)
			{
				ID[i] = feel[i];
			}
		}
		else if (*id == '3')
		{
			for (; type[i] != '\0'; i++)
			{
				s++;
			}
			Value = new char[s];
			for (i = 0; type[i] != '\0'; i++)
			{
				Value[i] = type[i];
			}
			Value[i] = '\0';
			s = 0;
			i = 0;
			char feel[7] = { 'm','a','k','i','n','g','\0' };
			ID = new char[7];
			for (i = 0; i < 7; i++)
			{
				ID[i] = feel[i];
			}
		}
		else if (*id == '4')
		{
			for (; type[i] != '\0'; i++)
			{
				s++;
			}
			Value = new char[s];
			for (i = 0; type[i] != '\0'; i++)
			{
				Value[i] = type[i];
			}
			Value[i] = '\0';
			s = 0;
			i = 0;
			char feel[12] = { 'c','e','l','e','b','r','a','i','n','g','\0' };
			ID = new char[12];
			for (i = 0; i < 12; i++)
			{
				ID[i] = feel[i];
			}
		}
	}
	void Print()
	{
		cout << " is " << ID << " " << Value << endl;
	}
};
class Date
{
private:
	char* day;
	char* month;
	char* year;
public:
	Date(const char* date = 0)
	{
		int s = 0;
		int i, j, T;
		j = 0;
		for (i = 0; date[i] != ' '; i++)
		{
			s++;
		}
		day = new char[s];
		for (i = 0; date[i] != ' '; i++, j++)
		{
			day[j] = date[i];
		}
		day[j] = '\0';
		s = 0;
		i++;
		for (; date[i] != ' '; i++)
		{
			s++;
		}
		j = 0;
		month = new char[s];
		i -= s;
		for (; date[i] != ' '; i++, j++)
		{
			month[j] = date[i];
		}
		month[j] = '\0';
		s = 0;
		i++;
		for (; date[i] != '\0'; i++)
		{
			s++;
		}
		year = new char[s];
		i -= s;
		j = 0;
		for (; date[i] != '\0'; i++, j++)
		{
			year[j] = date[i];
		}
		year[j] = '\0';
	}
	void Print()
	{
		cout << "Date : " << day << " / " << month << " / " << year << endl;
	}
};
class pages :public helper // Inherited from helper to use its functions
{
	char* id;
	char* title;
public:
	pages()
	{
		id = NULL;
		title = NULL;
	}
	pages(const char* p_id = 0, const char* p_title = 0)
	{
		int s = helper::getlength(p_id);
		id = new char[s + 1];
		int i = 0;
		for (; i < s; i++)
		{
			id[i] = p_id[i];
		}
		id[i] = '\0';
		s = helper::getlength(p_title);
		title = new char[s + 1];
		i = 0;
		for (; i < s; i++)
		{
			title[i] = p_title[i];
		}
		title[i] = '\0';
	}
	char* get_id()
	{
		return id;
	}
	char* get_title()
	{
		return title;
	}
	void set_title()
	{
		fstream page;
		int size = helper::getlength(id); // size of page id
		page.open("pages.txt", ios::in);
		if (page.is_open())
		{
			int page_id = 0, page_counter = 0;
			char line[100];
			while (page.getline(line, 100))
			{
				for (int i = 0; line[i] != ' '; i++)
				{
					page_id++;
				}
				if (page_id == size && size <= 2)
				{
					if (line[0] == id[0])
					{
						if (line[1] == id[1])
						{
							int k = 3; // k starts after space
							page_counter = helper::getcounterchar(k, '\0', line);
							title = new char[page_counter + 1];
							int p = 0;
							k = 3;
							for (; line[k] != '\0'; k++)
							{
								title[p] = line[k];
								p++;
							}
							title[p] = '\0';
						}
					}
				}
				else if (size > 2)
				{
					if (line[0] == id[0])
					{
						if (line[1] == id[1])
						{
							if (line[2] == id[2])
							{
								int k = 4; // k starts after space
								page_counter = helper::getcounterchar(k, '\0', line);
								title = new char[page_counter + 1];
								int p = 0;
								k = 4;
								for (; line[k] != '\0'; k++)
								{
									title[p] = line[k];
									p++;
								}
								title[p] = '\0';
							}
						}
					}
				}
				page_id = 0;
			}
			page.close();
		}
		else
		{
			cout << "Pages.txt not found" << endl;
		}
		printPage();
	}
	void printPage()
	{
		cout << "Page ID : " << id << "\nPage Name : " << title << endl;
	}
	~pages()
	{
		delete[]id;
		id = NULL;
		delete[]title;
		title = NULL;
	}
};
class user :public helper // Inherited from helper to use its functions
{
	char* user_id;
	char* fname;
	char* lname;
	pages** likedpages;   // Aggregation
	user** flist;		  // Aggregation
	int friendscount;
	int likedpagescount;
public:
	user()
	{
		user_id = NULL;
		fname = NULL;
		lname = NULL;
		likedpages = new pages * [10];
		for (int i = 0; i < 10; i++)
		{
			likedpages[i] = NULL;
		}
		flist = new user * [10];
		for (int i = 0; i < 10; i++)
		{
			flist[i] = NULL;
		}
		friendscount = 0;
		likedpagescount = 0;

	}
	user(char* u_id, char* f_name, char* l_name)
	{
		int s = helper::getlength(u_id);
		user_id = new char[s + 1];
		int u = 0;
		for (int i = 0; u_id[i] != '\0'; i++)
		{
			user_id[u] = u_id[i];
			u++;
		}
		user_id[u] = '\0';

		s = helper::getlength(f_name);
		fname = new char[s + 1];
		u = 0;
		for (int i = 0; f_name[i] != '\0'; i++)
		{
			fname[u] = f_name[i];
			u++;
		}
		fname[u] = '\0';

		s = helper::getlength(l_name);
		lname = new char[s + 1];
		u = 0;
		for (int i = 0; l_name[i] != '\0'; i++)
		{
			lname[u] = l_name[i];
			u++;
		}
		lname[u] = '\0';
		likedpages = NULL;
		flist = NULL;
		friendscount = 0;
		likedpagescount = 0;
	}
	user(char* u_id, char* f_name, char* l_name, user** friends, int cnt_fr, pages** liked_pages, int cnt_pg)
	{
		int s = helper::getlength(u_id);
		user_id = new char[s + 1];
		int u = 0;
		for (int i = 0; u_id[i] != '\0'; i++)
		{
			user_id[u] = u_id[i];
			u++;
		}
		user_id[u] = '\0';

		s = helper::getlength(f_name);
		fname = new char[s + 1];
		u = 0;
		for (int i = 0; f_name[i] != '\0'; i++)
		{
			fname[u] = f_name[i];
			u++;
		}
		fname[u] = '\0';

		s = helper::getlength(l_name);
		lname = new char[s + 1];
		u = 0;
		for (int i = 0; l_name[i] != '\0'; i++)
		{
			lname[u] = l_name[i];
			u++;
		}
		lname[u] = '\0';

		friendscount = cnt_fr;
		flist = new user * [cnt_fr];
		for (int i = 0; i < cnt_fr; i++)
		{
			flist[i] = new user(friends[i]->get_id(), friends[i]->get_fname(), friends[i]->get_lname());
			//flist[i] = friends[i];
		}

		likedpagescount = cnt_pg;
		likedpages = new pages * [cnt_pg];
		for (int i = 0; i < cnt_pg; i++)
		{
			//likedpages[i] = new pages(likedpages[i]->get_id(), likedpages[i]->get_title());
			likedpages[i] = liked_pages[i];
		}
	}
	char* get_id()
	{
		return user_id;
	}
	char* get_fname()
	{
		return fname;
	}
	char* get_lname()
	{
		return lname;
	}
	void setname()
	{
		fstream userinput;
		userinput.open("user.txt", ios::in);
		int size = helper::getlength(user_id), line_size = 0;         // for comparing user id's
		if (userinput.is_open())
		{
			char line[100];// use userinput.getline(line,100) for this if string using is not allowed

			int fname_counter = 0, lname_counter = 0;
			while (userinput.getline(line, 100))
			{
				for (int i = 0; line[i] != '\t'; i++) // for checking id's of users
				{
					line_size++;
				}
				if (line_size == size && size <= 2)
				{
					if (line[0] == user_id[0])
					{
						if (line[1] == user_id[1])  //if first two characters of id match 
						{
							int k = 3; // starting k from the space
							for (; line[k] != ' '; k++)
							{
								fname_counter++;
							}
							k++;
							for (; line[k] != '\t'; k++)
							{
								lname_counter++;
							}
							fname = new char[fname_counter + 1];
							lname = new char[lname_counter + 1];
							k = 3;
							int f = 0, l = 0; // for fname and lname saving
							for (; line[k] != ' '; k++)
							{
								fname[f] = line[k];
								f++;
							}
							fname[f] = '\0';
							k++;
							for (; line[k] != '\t'; k++)
							{
								lname[l] = line[k];
								l++;
							}
							lname[l] = '\0';
						}
					}
				}
				else if (size > 2)
				{
					if (line[0] == user_id[0])
					{
						if (line[1] == user_id[1])
						{
							if (line[2] == user_id[2])
							{
								int k = 4; // starting k from the space
								for (; line[k] != ' '; k++)
								{
									fname_counter++;
								}
								k++;
								for (; line[k] != '\t'; k++)
								{
									lname_counter++;
								}
								fname = new char[fname_counter + 1];
								lname = new char[lname_counter + 1];
								k = 4;
								int f = 0, l = 0; // for fname and lname saving
								for (; line[k] != ' '; k++)
								{
									fname[f] = line[k];
									f++;
								}
								fname[f] = '\0';
								k++;
								for (; line[k] != '\t'; k++)
								{
									lname[l] = line[k];
									l++;
								}
								lname[l] = '\0';
							}
						}
					}
				}
				line_size = 0;
			}
			userinput.close();
		}
		else
		{
			cout << "User text file not found" << endl;
		}
		//print();
	}
	void print()
	{
		cout << "User ID : " << user_id << "\nUser name  : " << fname << " " << lname << endl;
	}
	void setuser()
	{
		cout << "-----------------------------" << endl;
		cout << "User ID  : " << user_id << "\nUser Name  : " << fname << " " << lname << " Set as Current User Successfully";

	}
	void likedpagess()
	{
		cout << "Liked Pages :-\n";
		for (int i = 0; i < this->likedpagescount; i++)
		{
			likedpages[i]->printPage();
		}
	}void userfriends()
	{
		cout << "\nFriends :-\n";
		for (int i = 0; i < this->friendscount; i++)
		{
			flist[i]->print();
		}
		cout << "-----------------------------" << endl;
	}
	~user()
	{
		if (fname != NULL)
		{
			delete[]fname;
			fname = NULL;
		}
		if (lname != NULL)
		{
			delete[]lname;
			lname = NULL;
		}
		if (user_id != NULL)
		{
			delete[]user_id;
			user_id = NULL;
		}

	}
};
class comments :public helper, public user // Inherited from helper to use its functions and from user to get its data
{                                          // ie names of users who commented on a post etc
private:
	char* id,
		* post_id,
		* user_name,
		* text;
	int c_cnt;
public:
	comments()
	{
		id = NULL;
		post_id = NULL;
		user_name = NULL;
		text = NULL;
		c_cnt = 0;
	}
	comments(char* c_id, char* p_id, char* u_id, char* c_txt, int cnt)
	{
		c_cnt = cnt;
		int c = 0, p = 0, u = 0, t = 0;
		for (int i = 0; c_id[i] != '\0'; i++)
		{
			c++;
		}
		for (int i = 0; p_id[i] != '\0'; i++)
		{
			p++;
		}
		for (int i = 0; u_id[i] != '\0'; i++)
		{
			u++;
		}
		for (int i = 0; c_txt[i] != '\0'; i++)
		{
			t++;
		}
		id = new char[c + 1];
		post_id = new char[p + 1];
		user_name = new char[u + 1];
		text = new char[t + 1];
		int j = 0;
		for (int i = 0; c_id[i] != '\0'; i++)
		{
			id[j] = c_id[i];
			j++;
		}
		id[j] = '\0';
		j = 0;

		for (int i = 0; u_id[i] != '\0'; i++)
		{
			user_name[j] = u_id[i];
			j++;
		}
		user_name[j] = '\0';
		j = 0;

		for (int i = 0; p_id[i] != '\0'; i++)
		{
			post_id[j] = p_id[i];
			j++;
		}
		post_id[j] = '\0';
		j = 0;

		for (int i = 0; c_txt[i] != '\0'; i++)
		{
			text[j] = c_txt[i];
			j++;
		}
		text[j] = '\0';
		j = 0;
	}
	char* get_post_ID()
	{
		return post_id;
	}
	void print(char* Post_ID, comments** Allcomments)
	{
		cout << endl;
		for (int i = 0; i < 12; i++)
		{
			bool con = true;
			char* chk_Post_ID = Allcomments[i]->get_post_ID();
			for (int j = 0; chk_Post_ID[j] != '\0'; j++)
			{
				if (Post_ID[j] != chk_Post_ID[j])
				{
					con = false;
					break;
				}
			}
			if (con == true)
			{
				cout << Allcomments[i]->user_name << " wrote : \"" << Allcomments[i]->text << "\"" << endl;
			}
		}
	}
	~comments()
	{
		if (id != NULL)
		{
			delete[]id;
			id = NULL;
		}if (post_id != NULL)
		{
			delete[]post_id;
			post_id = NULL;
		}
		if (user_name != NULL)
		{
			delete[]user_name;
			user_name = NULL;
		}if (text != NULL)
		{
			delete[]text;
			text = NULL;
		}
	}
};
class Object
{
private:
	char* Name;
public:
	Object(char* name)
	{
		int s = 0;
		for (int i = 0; name[i] != '\0'; i++)
		{
			s++;
		}
		Name = new char[s];
		int i = 0;
		for (; name[i] != '\0'; i++)
		{
			Name[i] = name[i];
		}
		Name[i] = '\0';
	}
	virtual void Print_Name()
	{
		cout << Name << " ";
	}
};
class Post :public helper, public comments // Inherited from helper and comments to use their member functions
{
private:
	char* Post_ID;
	char* Post_type;           //-------------------------------//
	Date date;                 // Aggregation:					//
	char* Post_text;	       // Making date, Feeling_type,	//
	Activity* Feeling_type;    // Author, Liked_by, Allcomments	//
	Object* Author;		       // is aggregation				//
	Object** Liked_by;	       // Making objects of a class in	//
	int Liked_by_cnt;	       // another class is aggregation	//
	comments** Allcomments;    //-------------------------------//
public:
	Post()
	{
		Feeling_type = new Activity[1];
	}

	Post(char* post_type, char* post_ID, char* datee, char* post_text, comments** allcomments,
		Activity* act, char* shared_by, char** liked_by, int liked_by_cnt)
		:date(datee)
	{
		Allcomments = allcomments;

		Post_type = new char[2];
		Post_type[0] = post_type[0];
		Post_type[1] = '\0';
		//----------------------------------
		Liked_by_cnt = liked_by_cnt;
		//----------------------------------
		int s = helper::getlength(post_ID);
		Post_ID = new char[s + 1];
		int u = 0;
		for (int i = 0; post_ID[i] != '\0'; i++)
		{
			Post_ID[u] = post_ID[i];
			u++;
		}
		Post_ID[u] = '\0';
		//----------------------------------
		s = helper::getlength(post_text);
		Post_text = new char[s + 1];
		u = 0;
		for (int i = 0; post_text[i] != '\0'; i++)
		{
			Post_text[u] = post_text[i];
			u++;
		}
		Post_text[u] = '\0';
		//----------------------------------
		Feeling_type = act;
		//----------------------------------
		Author = new Object(shared_by);
		//----------------------------------
		Liked_by = new Object * [liked_by_cnt];
		for (int i = 0; i < liked_by_cnt; i++)
		{
			Liked_by[i] = new Object(liked_by[i]);
		}
		//----------------------------------
	}
	Post(char* post_type, char* post_ID, char* datee,
		char* post_text, comments** allcomments, char* shared_by
		, char** liked_by, int liked_by_cnt) :date(datee), Feeling_type()
	{
		Allcomments = allcomments;
		Post_type = new char[2];
		Post_type[0] = post_type[0];
		Post_type[1] = '\0';
		//----------------------------------
		Liked_by_cnt = liked_by_cnt;
		//----------------------------------
		int s = helper::getlength(post_ID);
		Post_ID = new char[s + 1];
		int u = 0;
		for (int i = 0; post_ID[i] != '\0'; i++)
		{
			Post_ID[u] = post_ID[i];
			u++;
		}
		Post_ID[u] = '\0';
		//----------------------------------
		s = helper::getlength(post_text);
		Post_text = new char[s + 1];
		u = 0;
		for (int i = 0; post_text[i] != '\0'; i++)
		{
			Post_text[u] = post_text[i];
			u++;
		}
		Post_text[u] = '\0';
		//----------------------------------
		Feeling_type = NULL;
		//----------------------------------
		Author = new Object(shared_by);
		//----------------------------------
		Liked_by = new Object * [liked_by_cnt];
		for (int i = 0; i < liked_by_cnt; i++)
		{
			Liked_by[i] = new Object(liked_by[i]);
		}
		//----------------------------------
	}
	void printpost()
	{
		cout << "-----------------------------" << endl;
		cout << "Post ID  : " << Post_ID << "\n";
		date.Print(); cout << "\n";
		Author->Print_Name();
		if (Post_type[0] == '2')
		{
			Feeling_type->Print();
		}
		cout << Post_text << endl;
		if (Liked_by_cnt > 0)
		{
			cout << "Liked by :-\n";
			for (int i = 0; i < Liked_by_cnt; i++)
			{
				if (i < Liked_by_cnt - 1)
				{
					Liked_by[i]->Print_Name();
					cout << ", ";
				}
				else
				{
					Liked_by[i]->Print_Name();
				}
			}
		}
		else
		{
			cout << "No likes yet\n";
		}


		comments::print(Post_ID, Allcomments);

		cout << endl;
	}
};
class Face_Book :public helper
{
private:
	//--------------------------------//
	// Aggregation in facbook class:- //
	//--------------------------------//
	// Making Pages, all_users,	      //
	// All_Posts, curr_user, t_f_list //
	// Act, allcomments is aggregation//
	// Making objects of a class in   //
	// another class is aggregation   //
	//--------------------------------//
	pages** Pages;
	user** all_users;
	user* curr_user;
	user** t_f_list;
	Post** All_Posts;
	Activity* Act;
	comments** allcomments;
	int lu;
public:
	Face_Book()
	{
		int cnt_fr = 0, cnt_pg = 0;
		int lp = 0;
		fstream file1;
		file1.open("pages.txt", ios::in);
		if (file1.is_open())
		{
			char* id, * title;
			char temp[100];
			while (file1.getline(temp, 100))
			{
				lp++;
			}
			file1.close();
			file1.open("pages.txt", ios::in);
			Pages = new pages * [lp];
			int ID_size = 0, Title_size = 0, ind = 0;
			char temp1[100];
			while (file1.getline(temp1, 100))
			{
				int i = 0;
				for (i = 0; temp1[i] != ' '; i++)
				{
					ID_size++;
				}
				id = new char[ID_size + 1];
				for (i = 0; temp1[i] != ' '; i++)
				{
					id[i] = temp1[i];
				}
				id[i] = '\0';
				for (i = ID_size + 1; temp1[i] != '\0'; i++)
				{
					Title_size++;
				}
				title = new char[Title_size + 1];
				int J = 0;
				for (i = ID_size + 1; temp1[i] != '\0'; i++, J++)
				{
					title[J] = temp1[i];
				}
				title[J] = '\0';
				Pages[ind] = new pages(id, title);
				ind++;
				Title_size = 0;
				ID_size = 0;
			}
			file1.close();
		}
		else
		{
			cout << "Pages file not found\n";
		}


		file1.open("user.txt", ios::in);
		if (file1.is_open())
		{
			int lu = 0, ind = 0;
			char* id, * fname, * lname, * friends, * liked_pages;
			char temp[200];
			while (file1.getline(temp, 200))
			{
				lu++;
			}
			file1.close();
			file1.open("user.txt", ios::in);
			t_f_list = new user * [lu];
			int size = 0;
			char temp1[100];
			while (file1.getline(temp1, 100))
			{
				int i = 0;
				int j = 0;
				int T = 0;
				//---------------------------------
				for (; temp1[i] != '\t'; i++)
				{
					size++;
				}
				id = new char[size + 1];
				i = 0;
				for (; temp1[i] != '\t'; j++, i++)
				{
					id[j] = temp1[i];
				}
				id[j] = '\0';
				i++;
				T = i;
				j = 0;
				size = 0;
				//---------------------------------
				for (; temp1[i] != ' '; i++)
				{
					size++;
				}
				fname = new char[size + 1];
				i = T;
				for (; temp1[i] != ' '; j++, i++)
				{
					fname[j] = temp1[i];
				}
				fname[j] = '\0';
				i++;
				T = i;
				j = 0;
				size = 0;
				//---------------------------------
				for (; temp1[i] != '\t'; i++)
				{
					size++;
				}
				lname = new char[size + 1];
				i = T;
				for (; temp1[i] != '\t'; j++, i++)
				{
					lname[j] = temp1[i];
				}
				lname[j] = '\0';
				i++;
				T = i;
				j = 0;
				size = 0;
				//---------------------------------
				t_f_list[ind] = new user(id, fname, lname);
				ind++;
			}

			//for (int i = 0; i < lu; i++)
			//{
			//	cout << t_f_list[i]->get_id();
			//	cout << t_f_list[i]->get_fname();
			//	cout << t_f_list[i]->get_lname();
			//	t_f_list[i]->print();
			//}
			file1.close();
		}
		else
		{
			cout << "Pages file not found\n";
		}

		lu = 0; int ind = 0;
		file1.open("user.txt", ios::in);
		if (file1.is_open())
		{
			char* id, * fname, * lname, * friends, * liked_pages;
			char temp[200];
			while (file1.getline(temp, 200))
			{
				lu++;
			}
			file1.close();
			file1.open("user.txt", ios::in);
			all_users = new user * [lu];
			int size = 0;
			char temp1[200];
			while (file1.getline(temp1, 200))
			{
				int i = 0;
				int j = 0;
				int T = 0;
				//---------------------------------
				for (; temp1[i] != '\t'; i++)
				{
					size++;
				}
				id = new char[size + 1];
				i = 0;
				for (; temp1[i] != '\t'; j++, i++)
				{
					id[j] = temp1[i];
				}
				id[j] = '\0';
				i++;
				T = i;
				j = 0;
				size = 0;
				//---------------------------------
				for (; temp1[i] != ' '; i++)
				{
					size++;
				}
				fname = new char[size + 1];
				i = T;
				for (; temp1[i] != ' '; j++, i++)
				{
					fname[j] = temp1[i];
				}
				fname[j] = '\0';
				i++;
				T = i;
				j = 0;
				size = 0;
				//---------------------------------
				for (; temp1[i] != '\t'; i++)
				{
					size++;
				}
				lname = new char[size + 1];
				i = T;
				for (; temp1[i] != '\t'; j++, i++)
				{
					lname[j] = temp1[i];
				}
				lname[j] = '\0';
				i++;
				T = i;
				j = 0;
				size = 0;
				CHK++;
				//---------------------------------
				for (; temp1[i] != '-'; i++)
				{
					size++;
				}
				friends = new char[size + 1];
				i = T;
				for (; temp1[i] != '-'; j++, i++)
				{
					friends[j] = temp1[i];
				}
				friends[j] = '\0';
				i += 3;
				T = i;
				j = 0;
				size = 0;

				int I = 0, tabs = 0;

				for (; friends[I] != '\0'; I++)
				{
					if (friends[I] == '\t')
					{
						tabs++;
					}
				}

				char** f_temp = new char* [tabs];
				user** f_list = new user * [tabs];
				cnt_fr = tabs;

				for (I = 0; I < tabs; I++)
				{
					int k = 0, J = 0;
					for (; friends[J] != '\0' && friends[J] != '\t'; k++, J++) {}
					f_temp[I] = new char[k];
				}
				int J = 0;
				for (I = 0; I < tabs; I++)
				{
					int k = 0;
					for (; friends[J] != '\0' && friends[J] != '\t'; k++, J++)
					{
						f_temp[I][k] = friends[J];
					}
					f_temp[I][k] = '\0';
					J++;
				}

				I = 0;
				for (int i = 0; i < lu; i++)
				{
					if (I < tabs)
					{
						bool con = true;
						char* chk = t_f_list[i]->get_id();
						char* chk_ = f_temp[I];
						for (int i = 0; chk_[i] != '\0'; i++)
						{
							if (chk[i] != chk_[i])
							{
								con = false;
								break;
							}
						}
						if (con == true)
						{
							f_list[I] = new user(t_f_list[i]->get_id(), t_f_list[i]->get_fname(), t_f_list[i]->get_lname());
							I++;
						}
					}
				}

				//for (int i = 0; i < tabs; i++)
				//{
				//	f_list[i]->print();
				//}

				//---------------------------------
				for (; temp1[i] != '-'; i++)
				{
					size++;
				}
				liked_pages = new char[size + 1];
				i = T;
				for (; temp1[i] != '-'; j++, i++)
				{
					liked_pages[j] = temp1[i];
				}
				liked_pages[j] = '\0';
				i = 0;
				T = 0;
				j = 0;
				size = 0;

				I = 0, tabs = 0;
				char** p_list;
				for (; liked_pages[I] != '\0'; I++)
				{
					if (liked_pages[I] == '\t')
					{
						tabs++;
					}
				}

				p_list = new char* [tabs];

				for (I = 0; I < tabs; I++)
				{
					int k = 0, J = 0;
					for (; liked_pages[J] != '\0' && liked_pages[J] != '\t'; k++, J++) {}
					p_list[I] = new char[k];
				}
				J = 0;
				for (I = 0; I < tabs; I++)
				{
					int k = 0;
					for (; liked_pages[J] != '\0' && liked_pages[J] != '\t'; k++, J++)
					{
						p_list[I][k] = liked_pages[J];
					}
					p_list[I][k] = '\0';
					J++;
				}

				pages** p_l;

				p_l = new pages * [tabs];
				cnt_pg = tabs;
				I = 0;
				for (int i = 0; i < lp; i++)
				{
					if (I < tabs)
					{
						bool con = true;
						char* chk = Pages[i]->get_id();
						char* chk_ = p_list[I];
						for (int i = 0; chk_[i] != '\0'; i++)
						{
							if (chk[i] != chk_[i])
							{
								con = false;
								break;
							}
						}
						if (con == true)
						{
							p_l[I] = new pages(Pages[i]->get_id(), Pages[i]->get_title());
							I++;
						}
					}
				}
				//---------------------------------
				all_users[ind] = new user(id, fname, lname, f_list, cnt_fr, p_l, cnt_pg);
				ind++;
			}
			file1.close();
		}
		else
		{
			cout << "User file not found\n";
		}



		int lc = 0;
		file1.open("comment.txt", ios::in);
		if (file1.is_open())
		{
			char* comment_id, * post_id, * user_id, * comment_text;
			char temp[200];
			int c_id = 0, p_id = 0, u_id = 0, c_text = 0, ind = 0;
			while (file1.getline(temp, 200))
			{
				lc++;
			}
			file1.close();
			allcomments = new comments * [lc];
			file1.open("comment.txt", ios::in);
			while (file1.getline(temp, 200))
			{
				int k = 0;
				int i = 0;// for saving data
				for (; temp[k] != '\t'; k++)
				{
					c_id++;
				}

				comment_id = new char[c_id + 1];
				int j = 0;
				for (; temp[i] != '\t'; i++)
				{
					comment_id[j] = temp[i];
					j++;
				}
				comment_id[j] = '\0';
				// for post id
				j = 0;
				k++;
				i = k;
				for (; temp[k] != '\t'; k++)
				{
					p_id++;
				}
				post_id = new char[p_id + 1];
				for (; temp[i] != '\t'; i++)
				{
					post_id[j] = temp[i];
					j++;
				}
				post_id[j] = '\0';
				j = 0;
				k++;
				i = k;
				// for user id
				for (; temp[k] != '\t'; k++)
				{
					u_id++;
				}
				user_id = new char[u_id + 1];
				for (; temp[i] != '\t'; i++)
				{
					user_id[j] = temp[i];
					j++;
				}
				user_id[j] = '\0';
				j = 0;
				k++;
				i = k;

				if (user_id[0] == 'u')
				{
					for (int i = 0; i < lu/*==>lines in user file*/; i++)
					{
						bool con = true;
						char* chk = all_users[i]->get_id();
						char* chk_ = user_id;
						for (int j = 0; chk_[j] != '\0'; j++)
						{
							if (chk[j] != chk_[j])
							{
								con = false;
								break;
							}
						}
						if (con == true)
						{
							int sf = 0, sl = 0;
							char* f_n = all_users[i]->get_fname();
							char* l_n = all_users[i]->get_lname();

							sf = helper::getlength(f_n);
							sl = helper::getlength(l_n);

							delete[]user_id;
							user_id = nullptr;
							user_id = new char[sf + sl + 2];

							int i = 0;
							for (int j = 0; f_n[j] != '\0'; j++, i++)
							{
								user_id[i] = f_n[j];
							}
							user_id[i] = ' ';
							i++;
							for (int j = 0; l_n[j] != '\0'; j++, i++)
							{
								user_id[i] = l_n[j];
							}
							user_id[i] = '\0';
							i++;
							break;
						}
					}
				}
				else if (user_id[0] == 'p')
				{
					for (int i = 0; i < lp/*==>lines in user file*/; i++)
					{
						bool con = true;
						char* chk = Pages[i]->get_id();
						char* chk_ = user_id;
						for (int j = 0; chk_[j] != '\0'; j++)
						{
							if (chk[j] != chk_[j])
							{
								con = false;
								break;
							}
						}
						if (con == true)
						{
							int st = 0;
							char* p_t = Pages[i]->get_title();

							st = helper::getlength(p_t);

							delete[]user_id;
							user_id = nullptr;
							user_id = new char[st + 1];

							int i = 0;
							for (int j = 0; p_t[j] != '\0'; j++, i++)
							{
								user_id[i] = p_t[j];
							}
							user_id[i] = '\0';
							i++;
							break;
						}
					}
				}

				//------------------------------------------------
				// for comment text
				for (; temp[k] != '\0'; k++)
				{
					c_text++;
				}
				comment_text = new char[c_text + 1];
				for (; temp[i] != '\0'; i++)
				{
					comment_text[j] = temp[i];
					j++;
				}
				comment_text[j] = '\0';
				j = 0;
				k++;
				i = k;

				allcomments[ind] = new comments(comment_id, post_id, user_id, comment_text, lc);
				ind++;
				c_text = 0;
				p_id = 0;
				u_id = 0;
				c_id = 0;
			}
			file1.close();
		}
		else
		{
			cout << "Comments file not found" << endl;
		}

		int lpo = 0; ind = 0;
		file1.open("post.txt", ios::in);
		if (file1.is_open())
		{
			char* post_type, * post_ID, * date, * post_text, * comm_text,
				* feeling_ID, * feeling_type = nullptr, * shared_by, * liked_by_1D, ** liked_by_IDs, ** liked_by_Names;
			int size = 0;
			char temp[200];
			while (file1.getline(temp, 200))
			{
				lpo++;
			}
			file1.close();
			file1.open("post.txt", ios::in);
			All_Posts = new Post * [lpo];
			char temp1[200];
			while (file1.getline(temp1, 200))
			{
				int i = 0;
				int j = 0;
				int T = 0;
				//---------------------------------
				for (; temp1[i] != '\t'; i++)
				{
					size++;
				}
				post_type = new char[size + 1];
				i = 0;
				for (; temp1[i] != '\t'; j++, i++)
				{
					post_type[j] = temp1[i];
				}
				post_type[j] = '\0';
				i++;
				T = i;
				j = 0;
				size = 0;
				//---------------------------------
				for (; temp1[i] != '\t'; i++)
				{
					size++;
				}
				post_ID = new char[size + 1];
				i = T;
				for (; temp1[i] != '\t'; j++, i++)
				{
					post_ID[j] = temp1[i];
				}
				post_ID[j] = '\0';
				i++;
				T = i;
				j = 0;
				size = 0;
				//---------------------------------
				for (; temp1[i] != '\t'; i++)
				{
					size++;
				}
				date = new char[size + 1];
				i = T;
				for (; temp1[i] != '\t'; j++, i++)
				{
					date[j] = temp1[i];
				}
				date[j] = '\0';
				i++;
				T = i;
				j = 0;
				size = 0;
				//---------------------------------
				for (; temp1[i] != '\t'; i++)
				{
					size++;
				}
				post_text = new char[size + 1];
				i = T;
				for (; temp1[i] != '\t'; j++, i++)
				{
					post_text[j] = temp1[i];
				}
				post_text[j] = '\0';
				i++;
				T = i;
				j = 0;
				size = 0;
				//---------------------------------
				if (*post_type == '2')
				{
					for (; temp1[i] != ' '; i++)
					{
						size++;
					}
					feeling_ID = new char[size + 1];
					i = T;
					for (; temp1[i] != ' '; j++, i++)
					{
						feeling_ID[j] = temp1[i];
					}
					feeling_ID[j] = '\0';
					i++;
					T = i;
					j = 0;
					size = 0;
					//---------------------------------
					for (; temp1[i] != '\t'; i++)
					{
						size++;
					}
					feeling_type = new char[size + 1];
					i = T;
					for (; temp1[i] != '\t'; j++, i++)
					{
						feeling_type[j] = temp1[i];
					}
					feeling_type[j] = '\0';
					i++;
					T = i;
					j = 0;
					size = 0;

					Act = new Activity(feeling_ID, feeling_type);
				}
				//---------------------------------
				for (; temp1[i] != '\t'; i++)
				{
					size++;
				}
				shared_by = new char[size + 1];
				i = T;
				for (; temp1[i] != '\t'; j++, i++)
				{
					shared_by[j] = temp1[i];
				}
				shared_by[j] = '\0';
				i += 4;
				T = i;
				j = 0;
				size = 0;
				if (shared_by[0] == 'u')
				{
					for (int i = 0; i < lu/*==>lines in user file*/; i++)
					{
						bool con = true;
						char* chk = all_users[i]->get_id();
						char* chk_ = shared_by;
						for (int j = 0; chk_[j] != '\0'; j++)
						{
							if (chk[j] != chk_[j])
							{
								con = false;
								break;
							}
						}
						if (con == true)
						{
							int sf = 0, sl = 0;
							char* f_n = all_users[i]->get_fname();
							char* l_n = all_users[i]->get_lname();

							sf = helper::getlength(f_n);
							sl = helper::getlength(l_n);

							delete[]shared_by;
							shared_by = nullptr;
							shared_by = new char[sf + sl + 2];

							int i = 0;
							for (int j = 0; f_n[j] != '\0'; j++, i++)
							{
								shared_by[i] = f_n[j];
							}
							shared_by[i] = ' ';
							i++;
							for (int j = 0; l_n[j] != '\0'; j++, i++)
							{
								shared_by[i] = l_n[j];
							}
							shared_by[i] = '\0';
							i++;
						}
					}
				}
				else if (shared_by[0] == 'p')
				{
					for (int i = 0; i < lp/*==>lines in user file*/; i++)
					{
						bool con = true;
						char* chk = Pages[i]->get_id();
						char* chk_ = shared_by;
						for (int j = 0; chk_[j] != '\0'; j++)
						{
							if (chk[j] != chk_[j])
							{
								con = false;
								break;
							}
						}
						if (con == true)
						{
							int st = 0;
							char* p_t = Pages[i]->get_title();

							st = helper::getlength(p_t);

							delete[]shared_by;
							shared_by = nullptr;
							shared_by = new char[st + 1];

							int i = 0;
							for (int j = 0; p_t[j] != '\0'; j++, i++)
							{
								shared_by[i] = p_t[j];
							}
							shared_by[i] = '\0';
						}
					}
				}
				//---------------------------------
				for (; temp1[i] != '-'; i++)
				{
					size++;
				}
				liked_by_1D = new char[size + 1];
				i = T;
				for (; temp1[i] != '-'; j++, i++)
				{
					liked_by_1D[j] = temp1[i];
				}
				liked_by_1D[j] = '\0';
				i = 0;
				T = 0;
				j = 0;
				size = 0;

				int I = 0, tabs = 0;

				for (; liked_by_1D[I] != '\0'; I++)
				{
					if (liked_by_1D[I] == '\t')
					{
						tabs++;
					}
				}

				liked_by_IDs = new char* [tabs];
				liked_by_Names = new char* [tabs];
				cnt_fr = tabs;

				for (I = 0; I < tabs; I++)
				{
					int k = 0, J = 0;
					for (; liked_by_1D[J] != '\0' && liked_by_1D[J] != '\t'; k++, J++) {}
					liked_by_IDs[I] = new char[k];
				}
				int J = 0;
				for (I = 0; I < tabs; I++)
				{
					int k = 0;
					for (; liked_by_1D[J] != '\0' && liked_by_1D[J] != '\t'; k++, J++)
					{
						liked_by_IDs[I][k] = liked_by_1D[J];
					}
					liked_by_IDs[I][k] = '\0';
					J++;
				}

				I = 0;
				for (int i = 0; i < tabs; i++)
				{
					if (liked_by_IDs[i][0] == 'u')
					{
						for (int i = 0; i < lu; i++)
						{
							if (I < tabs)
							{
								bool con = true;
								char* chk = all_users[i]->get_id();
								char* chk_ = liked_by_IDs[I];
								for (int j = 0; chk_[j] != '\0'; j++)
								{
									if (chk[j] != chk_[j])
									{
										con = false;
										break;
									}
								}
								if (con == true)
								{
									int sf = 0, sl = 0;
									char* f_n = all_users[i]->get_fname();
									char* l_n = all_users[i]->get_lname();

									sf = helper::getlength(f_n);
									sl = helper::getlength(l_n);

									liked_by_Names[I] = new char[sf + sl + 2];

									int i = 0;
									for (int j = 0; f_n[j] != '\0'; j++, i++)
									{
										liked_by_Names[I][i] = f_n[j];
									}
									liked_by_Names[I][i] = ' ';
									i++;
									for (int j = 0; l_n[j] != '\0'; j++, i++)
									{
										liked_by_Names[I][i] = l_n[j];
									}
									liked_by_Names[I][i] = '\0';
									i++;
									I++;
								}
							}
						}
					}
					else if (liked_by_IDs[i][0] == 'p')
					{
						for (int i = 0; i < lp; i++)
						{
							if (I < tabs)
							{
								bool con = true;
								char* chk = Pages[i]->get_id();
								char* chk_ = liked_by_IDs[I];
								for (int j = 0; chk_[j] != '\0'; j++)
								{
									if (chk[j] != chk_[j])
									{
										con = false;
										break;
									}
								}
								if (con == true)
								{
									int sp = 0;
									char* p_t = Pages[i]->get_title();

									sp = helper::getlength(p_t);

									liked_by_Names[I] = new char[sp + 1];

									int i = 0;
									for (int j = 0; p_t[j] != '\0'; j++, i++)
									{
										liked_by_Names[I][i] = p_t[j];
									}
									liked_by_Names[I][i] = '\0';
									I++;
								}
							}
						}
					}
				}
				//---------------------------------
				if (*post_type == '2')
				{
					All_Posts[ind] = new Post(post_type, post_ID, date, post_text, allcomments,
						Act, shared_by, liked_by_Names, tabs);
				}
				else
				{
					All_Posts[ind] = new Post(post_type, post_ID, date, post_text, allcomments,
						shared_by, liked_by_Names, tabs);
				}
				ind++;
			}
			file1.close();
		}
		else
		{
			cout << "Pages file not found\n";
		}
	}

	void PPrint()
	{
		for (int i = 0; i < 11; i++)
		{
			All_Posts[i]->printpost();
		}
		cout << "-----------------------------" << endl;
	}
	void currentuser(int index)
	{
		if (index > 20)
		{
			cout << "There are 20 Users only!. Enter Correct User ID" << endl;
		}
		else
		{
			index = index - 1;
			all_users[index]->setuser();
			cout << "\n-----------------------------------";
			cout << "\nCommand:		View Friendlist" << endl;
			all_users[index]->userfriends();
			cout << "\nCommand:		View Liked Pages" << endl;
			all_users[index]->likedpagess();
		}
	}
	void home()
	{
		cout << "\n-----------------------------------";
		cout << "\nCommand:	View Home" << endl;
		cout << "-----------------------------------" << endl;
		for (int i = 0; i < 11; i++)
		{
			All_Posts[i]->printpost();
		}
		cout << "-----------------------------------" << endl;
	}
};

int main()
{
	Face_Book fb;
	cout << "-----------------------------------" << endl;
	int ID; cout << ":: Enter 1,2 3 , Dont enter u1, u2, u3\nEnter ID : "; cin >> ID;
	cout << "Command: set user to u" << ID << endl;
	fb.currentuser(ID);
	fb.home();
	return 0;
}