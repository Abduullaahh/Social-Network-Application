# Social-Network-Application
This is a C++ program that is a simplified version of a social media platform. Here's a breakdown of the code:

The helper class contains various helper functions for string manipulation.
    
The Activity class represents an activity. It has two private data members: ID and Value. The class provides a constructor and a Print() function to display the activity.
    
The Date class represents a date. It has three private data members: day, month, and year. The class provides a constructor and a Print() function to display the date.
    
The pages class represents pages. It is derived from the helper class. It has two private data members: id and title. The class provides constructors, getter and setter functions, and a printPage() function to display page details.
    
The user class represents users. It is also derived from the helper class. It has several private data members, including user_id, fname, lname, likedpages, flist, friendscount, and likedpagescount. The class provides constructors, getter and setter functions, and a setname() function to set the user's name based on input.

: :Facebook class and its member variables and functions:

pages** Pages: A pointer to a dynamically allocated array of pointers to pages objects.

user** all_users: A pointer to a dynamically allocated array of pointers to user objects.

user* curr_user: A pointer to a user object representing the current user.
user** t_f_list: A pointer to a dynamically allocated array of pointers to user objects representing the friend list.
Post** All_Posts: A pointer to a dynamically allocated array of pointers to Post objects representing all the posts.
Activity* Act: A pointer to an Activity object.
comments** allcomments: A pointer to a dynamically allocated array of pointers to comments objects representing all the comments.
int lu: An integer variable representing the number of users.
Face_Book(): Constructor function that initializes the Face_Book object and reads data from files to populate the member variables.
