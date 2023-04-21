//
// Created by dingjing on 23-4-21.
//

#ifndef GRACEFUL_IBUS_IBUS_VERSION_H
#define GRACEFUL_IBUS_IBUS_VERSION_H
#define IBUS_MAJOR_VERSION				(PROJECT_VERSION_MAJOR)

/**
 * IBUS_MINOR_VERSION:
 *
 * IBus minor version.
 */
#define IBUS_MINOR_VERSION				(PROJECT_VERSION_MINOR)

/**
 * IBUS_MICRO_VERSION:
 *
 * IBus micro version.
 */
#define IBUS_MICRO_VERSION				(PROJECT_VERSION_PATCH)

/**
 * IBUS_CHECK_VERSION:
 * @major: Major version of ibus.
 * @minor: Minor version of ibus.
 * @micro: Micro version of ibus.
 *
 * Check whether the current IBus version is equal to or greater than
 * given major.minor.micro.
 */
#define	IBUS_CHECK_VERSION(major,minor,micro)	\
    (IBUS_MAJOR_VERSION > (major) || \
     (IBUS_MAJOR_VERSION == (major) && IBUS_MINOR_VERSION > (minor)) || \
     (IBUS_MAJOR_VERSION == (major) && IBUS_MINOR_VERSION == (minor) && \
      IBUS_MICRO_VERSION >= (micro)))

#endif //GRACEFUL_IBUS_IBUS_VERSION_H
