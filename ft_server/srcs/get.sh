service mysql restart
mysql -u root -e "CREATE DATABASE 1337db;"
mysql -u root -e "CREATE USER '1337user'@localhost IDENTIFIED BY '1337';"
mysql -u root -e "GRANT ALL PRIVILEGES ON * . * TO '1337user'@localhost;"
mysql -u root -e "FLUSH PRIVILEGES;"
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp
wp core download --allow-root
wp core config --dbhost=localhost --dbname=1337db --dbuser=1337user --dbpass=1337 --allow-root
wp core install --url=localhost --title="1337 ft_server" --admin_name=1337_admin --admin_password=73311337 --admin_email=root@root.fr --allow-root
