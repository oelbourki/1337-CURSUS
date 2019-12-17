FROM debian:buster
RUN apt-get update && apt-get -y install nginx mariadb-server php7.3-fpm php7.3-mbstring php7.3-mysql unzip nano curl
COPY /srcs/phpMyAdmin.zip /var/www/html/
RUN unzip /var/www/html/phpMyAdmin.zip -d /var/www/html/ && rm -rf /var/www/html/phpMyAdmin.zip
COPY /srcs/default /etc/nginx/sites-enabled
COPY /srcs/*.sh /var/www/html/
RUN mkdir /etc/nginx/ssl
COPY /srcs/ssl/* /etc/nginx/ssl/
WORKDIR /var/www/html/
RUN sh get.sh
EXPOSE 80 443 3306
CMD ["sh" ,"set.sh"]