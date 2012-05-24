<?php
/**
 * @file
 * dragndrop_example.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function dragndrop_example_default_rules_configuration() {
  $items = array();
  $items['rules_add_attendee_to_meeting'] = entity_import('rules_config', '{ "rules_add_attendee_to_meeting" : {
      "LABEL" : "Add attendee to meeting",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "rb_misc" ],
      "ON" : [ "rb_misc_trigger_page_add_attendee_callback_http_response" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "argument-entity-id--node-1" ],
            "type" : { "value" : { "meeting" : "meeting" } }
          }
        },
        { "node_is_of_type" : {
            "node" : [ "argument-entity-id--node-2" ],
            "type" : { "value" : { "person" : "person" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "list\\u003Centity\\u003E", "value" : [ "" ] },
            "PROVIDE" : { "variable_added" : { "variable_added" : "Added variable" } }
          }
        },
        { "list_add" : {
            "list" : [ "variable-added" ],
            "item" : [ "argument-entity-id--node-1" ]
          }
        },
        { "list_add" : {
            "list" : [ "variable-added" ],
            "item" : [ "argument-entity-id--node-2" ]
          }
        },
        { "entity_create" : {
            "USING" : {
              "type" : "relation",
              "param_relation_type" : "attendee",
              "param_endpoints" : [ "variable-added" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "redirect" : { "url" : "node\\/[argument-entity-id--node-1:nid]" } }
      ]
    }
  }');
  return $items;
}
