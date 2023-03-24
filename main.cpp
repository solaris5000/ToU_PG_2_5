#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout; 
using std::endl;
using std::cin;
using std::getline;

class Track{
	protected:
		string name;
		int length_seconds;
		void virtual set_info() = 0;
		void virtual get_info() = 0;
};

// сделать реализацию
class Song : protected Track{
	private:
		string text;
		string author;
		
	public:
		Song(){
			this->name = "Unknown";
			this->text = "";
			this->author = "None";
		}
		
		void set_info(){
			cin.clear();
			cout << "Put the name oh the name of this Song " << endl;
			getline(cin, this->name);
			
			cout << "Put the name of author of this \"" << this->name << "\"" << endl;
			getline(cin, this->author);
			
			cout << "Put text here: \n";
			getline(cin, this->text);
			
			cout << "Which is the lenght of \"" << this->name << "\"" << endl;
			string tmp;
			getline(cin, tmp);

			this->length_seconds = std::stoi(tmp);
			
			return;
		};
		
		void get_info(){
			cout << "Name: " << this->name << endl;
			cout << "Author: "<< this->author << endl;
			cout << "Length: "<< this->length_seconds << " sec.\n";
			cout << "Text: " << this->text << endl;
			
			return;
		};

		int get_length()
		{
			return this->length_seconds;
		}
};

// сделать реализацию
class Instrumental : protected Track{
	private:
		std::vector<string> instruments;
		
	public:
		
		Instrumental(){
			this->name = "Unknown";
			this->length_seconds = 0;
		}
		
		void add_instruments(){
			cout << "Dobavlyai instuments ili najmi ENTER dlya zaversheniya:\n";
			string temp = "";
			getline(cin, temp);

			while (temp != "")
			{
				instruments.push_back(temp);
				getline(cin, temp);
			}
			return;
		}
		
		void remove_instrument(){
			cout << "Kavo tebe ubrat?\n";
			int i = 0;
			for (string intsr : this->instruments) {
				cout << i << ". " << intsr << endl;
				i++;
			}

			string tmp;
			getline(cin, tmp);

			i = std::stoi(tmp);
			auto iter = this->instruments.cbegin();
			this->instruments.erase(iter + i);

			return;
		}
		
		void set_info(){
			cin.clear();
			cout << "Put the name oh the name of this instrumental track " << endl;
			getline(cin, this->name);

			this->add_instruments();

			cout << "Which is the lenght of \"" << this->name << "\"" << endl;
			string tmp;
			getline(cin, tmp);

			this->length_seconds = std::stoi(tmp);
			
			
			return;
		};
		
		void get_info(){
			cout << "Name: " << this->name << endl;

			cout << "Length: " << this->length_seconds << " sec.\n";
			cout << "Instruments: " << endl;
			for (string intsr : this->instruments) {
				cout << " | " << intsr << endl;
			}


			return;
		};
		
		int get_length()
		{
			return this->length_seconds;
		}
};

class Album{
	private:
		std::vector<Song> songs;
		std::vector<Instrumental> instrs;
		int total_tracks;
		string author;
		string genre;
		int year;
		int total_length_seconds;
	
	public:
		
		Album(){
			this->total_tracks = 0;
			this->total_length_seconds = 0;
			this->author = "None";
			this->genre = "Unknown";
			this->year = 0;
		}
		
		void add_track(Song song){
			this->songs.push_back(song);
			this->total_length_seconds += song.get_length();
		}
		
		void add_track(Instrumental instr){
			this->instrs.push_back(instr);
			this->total_length_seconds += instr.get_length();
		}
		
		
		void display_tracks(){
			for (Song song : this->songs) {
				song.get_info();
			}

			for (Instrumental instr : this->instrs) {
				instr.get_info();
			}
		}
		
		void set_info(){
			cin.clear();
			cout << "Put the name of author of this Album " << endl;
			getline(cin, this->author);

			cout << "Put genre here: \n";
			getline(cin, this->genre);

			cout << "Which is the year of birth of this Album " << endl;
			string tmp;
			getline(cin, tmp);

			this->year = std::stoi(tmp);
			
			return;
		}
		
		void get_info(){
			cout << "Author : " << this->author << endl;
			cout << "Genre : " << this->genre << endl;
			cout << "Year : " << this->year << endl;
			cout << "Total tracks : " << this->total_tracks << endl;
			cout << "Total lenght in seconds : " << this->total_length_seconds << " s." << endl;
			this->display_tracks();

			return;
		}
		
		
	
};

class Collection{
	private:
		string name;
		string owner;
		std::vector<Album> albums;
	public:
		
		Collection(){
			this->name = "Unknown";
			this->owner = "None";
		}

		void add_album(Album album) {
			this->albums.push_back(album);
			return;
		}
		
		void set_info() {
			cin.clear();
			cout << "Put the name of this Colection " << endl;
			getline(cin, this->name);

			cout << "Put owner here: \n";
			getline(cin, this->owner);
			
			return;
		}

		void get_info() {
			cout << "Name : " << this->name << endl;
			cout << "Owner : " << this->owner << endl;

			for (Album a : albums) {
				a.get_info();
			}

			return;
		}
};


int main(){

	Song song1, song2;
	Instrumental sin_;

	Album sinsofsin;

	Collection col;

	song1.set_info();
	song2.set_info();
	sin_.set_info();
	sin_.remove_instrument();

	sinsofsin.set_info();
	sinsofsin.add_track(song1);
	sinsofsin.add_track(song2);
	sinsofsin.add_track(sin_);

	col.set_info();

	col.add_album(sinsofsin);

	col.get_info();
	
	
	return 0;
}
