core = 7.x
api = 2

projects[drupal][version] = 7.14

; patch to fix contextual link display when contextual links are embedded within each other
projects[drupal][patch][] = "http://drupal.org/files/1216776-contextual-links-nested-23-d7.patch"

projects[dragndrop][type] = "profile"
projects[dragndrop][download][type] = "git"
projects[dragndrop][download][url] = "git@github.com:darrenmothersele/dragndrop.git"
