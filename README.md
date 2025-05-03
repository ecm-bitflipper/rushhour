Binary Arts, which eventually morphed into ThinkFun, made some interesting, challenging, and fun puzzles which centered around getting a target vehicle out of a parking lot that is jammed with other cars that need to be juggled around in order to escape.  Their flagship puzzle game was Rush Hour, but then it evolved from there into spin-off puzzle games.  If you are not familiar with Rush Hour, you can go here to learn more:

https://www.thinkfun.com/

Rush Hour is played on a 6x6 grid.  The two spin-offs that I enjoyed were Railroad Rush Hour, and my favorite, Safari, both of which are played on a 7x7 grid.  The games are typically available on eBay, though the spin-offs tend to be more expensive as they weren't made in the same quantity as Rush Hour was.  More on that lower down.

If you run out of Rush Hour puzzle cards, you can generate an almost endless number of puzzles here:

https://www.michaelfogleman.com/static/rush/

The catch here is that you need pylons.  If you have access to a 3D printer (check with your local library, where I live they have free 3D printing!) you can easily and quickly make the pylons.  The Binary Arts and ThinkFun boards differed in size so choose the model you need for your board:

Binary Arts:  https://www.printables.com/model/605684-binary-arts-rush-hour-traffic-cone-remix-of-mini-t<br>
ThinkFun: https://www.printables.com/model/661067-thinkfun-rush-hour-traffic-cone-remix-of-mini-traf

So then on to Railroad Rush Hour and Safari and how to generate new puzzle boards for those.  That is where this code comes in.  I first must say that I did not develop this from scratch.  It is entirely rooted in code written years ago by Henrik Theiling.

https://theiling.de/

The code uses a brute force algorithm to discover solvable puzzle boards so you need to set it and forget it for a few hours and you should have some playable boards.

I was unable to figure out how to modernize the code for modern versions of Ubuntu/gcc so if you like this idea, you're going to need a very old Ubuntu version.  If you follow my instructions here carefully you should be successful.

https://old-releases.ubuntu.com/releases/9.10/

Download PC (Intel x86) desktop CD

https://www.virtualbox.org/

Download, install, and run Oracle VirtualBox

New - Name = Ubuntu_32, ISO image = Select the file you downloaded in the previous step

Hardware tab - Base Memory = 4096MB, Processors = 4

Hard Disk tab - Create Virtual Hard Disk Now - 32GB

Hit OK but hit Settings, go to the Network tab, select Cable Connected.  Hit Okay.

Start

Select English (or if you prefer a different language), Install Ubuntu, just step through all the selections, everything should just be intuitive or default.

If it hangs, which it does have a tendency to do, probably because it is so old, in the VirtualBox menu, do Machine->Reset and try again.

Login to Ubuntu.  Open a terminal (Applications->Terminal).

cd /etc/apt<br>
sudo vi sources.list

This is where you need some Unix skills to use vi.  Put a comment marker (#) in front of every line that does not have one.  Then at the end of the file add this:

http://old-releases.ubuntu.com/ubuntu karmic universe main restricted multiverse<br>
http://old-releases.ubuntu.com/ubuntu karmic-updates universe main restricted multiverse<br>
http://old-releases.ubuntu.com/ubuntu karmic-security universe main restricted multiverse<br>
http://old-releases.ubuntu.com/ubuntu karmic-backports universe main restricted multiverse<br>

Save the file and exit vi.

sudo apt-get update<br>
sudo apt-get install g++

Now you finally need the code here from github.  This ancient version of Ubuntu won't be able to connect to github because it's encryption capabilities aren't up to modern standards.  You'll need to download it on a more modern OS/browser and maybe use a USB stick to get it over to Ubuntu.  Unzip somewhere in your home folder.

cd liberror-2.1.89882<br>
make<br>
sudo make install

cd ..<br>
cd rush_hour-0.2.9<br>
make

Now you're ready to generate Railroad Rush Hour or Safari boards!  Examples:

Railroad Rush Hour:

./rush_hour --random --pylons

Safari:

./rush_hour --random --safari --pylons

Okay, so coming back to the availability of these games.  You'll need one of them, Railroad Rush Hour is the most available on eBay.  Safari, when it comes up for sale, is a lot more expensive.  I actually never bought Safari.  I made 3D printed game pieces and re-used the Railroad Rush Hour board.  I hope to publish those 3D models soon and will update this README with the link.

