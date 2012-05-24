<?php
/**
 * @file
 * dragndrop_example.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function dragndrop_example_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'add_attendee_callback';
  $page->task = 'page';
  $page->admin_title = 'Add attendee callback';
  $page->admin_description = '';
  $page->path = 'add-attendee/%meeting/%person';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'meeting' => array(
      'id' => 1,
      'identifier' => 'Meeting Node',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    'person' => array(
      'id' => 2,
      'identifier' => 'Person Node',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_add_attendee_callback_http_response';
  $handler->task = 'page';
  $handler->subtask = 'add_attendee_callback';
  $handler->handler = 'http_response';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Add attendee to meeting',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '301',
    'destination' => '',
    'rb_misc_trigger' => 1,
  );
  $page->default_handlers[$handler->name] = $handler;
  $pages['add_attendee_callback'] = $page;

  return $pages;

}
