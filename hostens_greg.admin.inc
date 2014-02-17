<?php

function hostens_greg_admin() {
    $form = array();

    $nodes = node_load_multiple(array(), array('type' => 'page_d_accueil'));
    foreach($nodes as $key => $node) {
        $nodes[$node->nid] = $node->title;
    }
    $form['hostens_greg_accueil_fr'] = array(
      '#type' => 'select',
      '#title' => t('Noeud accueil FR'),
      '#default_value' => variable_get('hostens_greg_accueil_fr', NULL),
      '#options' => $nodes,
    );
    $form['hostens_greg_accueil_en'] = array(
      '#type' => 'select',
      '#title' => t('Noeud accueil EN'),
      '#default_value' => variable_get('hostens_greg_accueil_en', NULL),
      '#options' => $nodes,
    );
    
    $form['hostens_greg_accueil_fonctionnalites'] = array(
      '#type' => 'textfield',
      '#title' => t('Fonctionnalités'),
      '#default_value' => variable_get('hostens_greg_accueil_fonctionnalites', NULL),
    );

    return system_settings_form($form);
}