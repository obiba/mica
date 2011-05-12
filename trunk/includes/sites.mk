#
# Mica Sites Makefile
# Requires drush 4+ to be installed: http://drush.ws/
#

#
# Your site
#
site_db_name=mica_site
site_name=MicaSite
site_dir_name=site.mica-obiba.org
site_account_name=admin         
site_account_pass=admin

#
# Clean urls: 0/1
#
clean_url=0

#
# Profile
#

profile=mica_standard

#
# Site
#

default-site:
	cd $(installdir)/$(micadir) && \
	$(drushexec) site-install $(profile) --db-url=mysql://$(db_user):$(db_pass)@localhost/mica --site-name=Mica --clean-url=$(clean_url) --yes

site:
	cd $(installdir)/$(micadir) && \
	$(drushexec) site-install $(profile) --db-url=mysql://$(db_user):$(db_pass)@localhost/$(site_db_name) --site-name=$(site_name) --sites-subdir=$(site_dir_name) --clean-url=$(clean_url) --account-name=$(site_account_name) --account-pass=$(site_account_pass)


